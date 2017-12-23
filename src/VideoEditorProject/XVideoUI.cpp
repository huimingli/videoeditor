#include "XVideoUI.h"
#include<qfiledialog.h>
#include<string>
#include<qmessagebox.h>
#include"XVideoThread.h"
#include"XFilter.h"
using namespace std;
static bool pressSlider = false;
static bool isExport = false;
XVideoUI::XVideoUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	qRegisterMetaType<cv::Mat>("cv::Mat");
	QObject::connect(XVideoThread::Get(),//信号发出的对象
		SIGNAL(viewImage1(cv::Mat)),//信号
		ui.src1Video,//槽接收的对象
		SLOT(setImage(cv::Mat))//槽
		);
	//输出视频显示信号
	QObject::connect(XVideoThread::Get(),//信号发出的对象
		SIGNAL(viewDes(cv::Mat)),//信号
		ui.des,//槽接收的对象
		SLOT(setImage(cv::Mat))//槽
	);

	//导出视频显示信号
	QObject::connect(XVideoThread::Get(),//信号发出的对象
		SIGNAL(saveEnd()),//信号
		this,//槽接收的对象
		SLOT(exportEnd())//槽
	);

	pause();

	startTimer(40);//启动计时器
}
void XVideoUI::open() {
	QString name = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("请选择视频文件"));
	if (name.isEmpty()) 
		return;
	string file = name.toLocal8Bit().data();//防止文件名中有中文
	if (!XVideoThread::Get()->open(file)) {
		QMessageBox::information(0, "", name+"open failed");
		return;
	}
	/*QMessageBox::information(0, "", name);*/
}

void XVideoUI::timerEvent(QTimerEvent * e)
{
	if (pressSlider)//正在拖动时，不设置移动
		return;
	double pos = XVideoThread::Get()->getPos();
	ui.playSlider->setValue(pos * 1000);
}

void XVideoUI::sliderPress()
{
	pressSlider = true;
}

void XVideoUI::sliderRelease()
{
	pressSlider = false;
}

//滑动条拖动
void XVideoUI::setPos(int pos)
{
	XVideoThread::Get()->seek((double)pos / 1000);
}

void XVideoUI::set()
{
	XFilter::Get()->clear();
	//对比度和亮度的设置
	if (ui.bright->value() > 0 ||
		ui.contrast->value() >1) {
		XFilter::Get()->addTask(XTask{ XTASK_GAIN,{(double)(ui.bright->value()),ui.contrast->value()} });
	}
}
void XVideoUI::exportVideo()
{
	
	if (isExport) {
		//停止导出
		XVideoThread::Get()->stopSave();
		isExport = false;
		ui.exportButton->setText("start export");
		return;
	}
	//开始导出
	QString name = QFileDialog::getSaveFileName(this,"save","out1.avi");
	if (name.isEmpty())
		return;
	std::string filename = name.toLocal8Bit().data();
	if (XVideoThread::Get()->startSave(filename)) {
		isExport = true;
		ui.exportButton->setText("stop export");
	}
}

//槽，视频导出结束时接收信息
void XVideoUI::exportEnd()
{
	isExport = false;
	ui.exportButton->setText("start export");
}

void XVideoUI::play()
{
	ui.pauseButton->show();
	ui.pauseButton->setGeometry(ui.playButton->geometry());
	ui.playButton->hide();
	XVideoThread::Get()->play();
}

void XVideoUI::pause()
{
	ui.playButton->show();
	ui.playButton->setGeometry(ui.pauseButton->geometry());
	ui.pauseButton->hide();
	XVideoThread::Get()->pause();
}
