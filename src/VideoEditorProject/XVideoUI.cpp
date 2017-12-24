#include "XVideoUI.h"
#include<qfiledialog.h>
#include<string>
#include<qmessagebox.h>
#include"XVideoThread.h"
#include"XFilter.h"
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
using namespace std;
static bool pressSlider = false;
static bool isExport = false;
static bool isColor = true;
static bool isMark = false;
static bool isBlend = false;
static bool isMerge = false;
XVideoUI::XVideoUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	qRegisterMetaType<cv::Mat>("cv::Mat");
	QObject::connect(XVideoThread::Get(),//�źŷ����Ķ���
		SIGNAL(viewImage1(cv::Mat)),//�ź�
		ui.src1Video,//�۽��յĶ���
		SLOT(setImage(cv::Mat))//��
		);

	

	//�����Ƶ��ʾ�ź�
	QObject::connect(XVideoThread::Get(),//�źŷ����Ķ���
		SIGNAL(viewDes(cv::Mat)),//�ź�
		ui.des,//�۽��յĶ���
		SLOT(setImage(cv::Mat))//��
	);

	//������Ƶ��ʾ�ź�
	QObject::connect(XVideoThread::Get(),//�źŷ����Ķ���
		SIGNAL(saveEnd()),//�ź�
		this,//�۽��յĶ���
		SLOT(exportEnd())//��
	);
	QObject::connect(XVideoThread::Get(),//�źŷ����Ķ���
		SIGNAL(viewImage2(cv::Mat)),//�ź�
		ui.src2Video,//�۽��յĶ���
		SLOT(setImage(cv::Mat))//��
	);
	pause();

	startTimer(40);//������ʱ��
}
void XVideoUI::open() {
	QString name = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("��ѡ����Ƶ�ļ�"));
	if (name.isEmpty()) 
		return;
	string file = name.toLocal8Bit().data();//��ֹ�ļ�����������
	if (!XVideoThread::Get()->open(file)) {
		QMessageBox::information(0, "", name+"open failed");
		return;
	}
	play();
	/*QMessageBox::information(0, "", name);*/
}

void XVideoUI::timerEvent(QTimerEvent * e)
{
	if (pressSlider)//�����϶�ʱ���������ƶ�
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

//�������϶�
void XVideoUI::setPos(int pos)
{
	XVideoThread::Get()->seek((double)pos / 1000);
}

void XVideoUI::set()
{
	XFilter::Get()->clear();
	isColor = true;
	//��Ƶͼ��Ĳü�
	bool isClip = false;
	double cx = ui.cx->value();
	double cy = ui.cy->value();
	double cw = ui.cw->value();
	double ch = ui.ch->value();

	if (cx + cy + cw + ch > 0.0001) {
		isClip = true;
		XFilter::Get()->addTask(XTask{ XTASK_CLIP,{ cx,cy,cw,ch } });
		double w = XVideoThread::Get()->width;
		double h = XVideoThread::Get()->height;
		XFilter::Get()->addTask(XTask{ XTASK_RESIZE,{ w,h } });
	}
	bool isPy = false;
	int down = ui.pydown->value();
	int up = ui.pyup->value();
	if (down > 0) {
		isPy = true;
		XFilter::Get()->addTask(XTask{ XTASK_PYDOWN,{ (double)down} });
		int w = XVideoThread::Get()->width;
		int h = XVideoThread::Get()->height;
		for (int i = 0; i < down; i++) {
			w /= 2;
			h /= 2;
		}
		ui.width->setValue(w);
		ui.height->setValue(h);
	}
	if (up > 0) {
		isPy = true;
		XFilter::Get()->addTask(XTask{ XTASK_PYUP,{ (double)up } });
		int w = XVideoThread::Get()->width;
		int h = XVideoThread::Get()->height;
		for (int i = 0; i < up; i++) {
			w *= 2;
			h *= 2;
		}
		ui.width->setValue(w);
		ui.height->setValue(h);
	}
	//������Ƶ�ĳߴ�
	double w = ui.width->value();
	double h = ui.height->value();
	if (!isMerge&&!isClip&&!isPy && w > 0 && h > 0) {
		XFilter::Get()->addTask(XTask{ XTASK_RESIZE,{ w,h } });
	}
	//�ԱȶȺ����ȵ�����
	if (ui.bright->value() > 0 ||
		ui.contrast->value() >1) {
		XFilter::Get()->addTask(XTask{ XTASK_GAIN,{(double)(ui.bright->value()),ui.contrast->value()} });
	}
	//�Ҷ�ͼ
	if (ui.color->currentIndex() == 1) {
		isColor = false;
		XFilter::Get()->addTask(XTask{ XTASK_GRAY });
	}
	 
	//ͼ����ת 1 90 2 180 3 270
	if (ui.rotate->currentIndex() == 1) {
		XFilter::Get()->addTask(XTask{XTASK_ROTATE_90});
	}
	else if (ui.rotate->currentIndex() == 2) {
		XFilter::Get()->addTask(XTask{ XTASK_ROTATE_180 });
	}
	else if (ui.rotate->currentIndex() == 3) {
		XFilter::Get()->addTask(XTask{ XTASK_ROTATE_270});
	}

	//ͼ����
	if (ui.flip->currentIndex() == 1) {
		XFilter::Get()->addTask(XTask{ XTASK_FLIPX });
	}
	else if (ui.flip->currentIndex() == 2) {
		XFilter::Get()->addTask(XTask{ XTASK_FLIPY });
	}
	else if (ui.flip->currentIndex() == 3) {
		XFilter::Get()->addTask(XTask{ XTASK_FLIPXY });
	}
	 
	//ˮӡ
	if (isMark) {
		double x = ui.mx->value();
		double y = ui.my->value();
		double a = ui.ma->value();
		XFilter::Get()->addTask(XTask{ XTASK_MARK,{x,y,a} });
	}

	if (isBlend) {
		double a = ui.ba->value();
		XFilter::Get()->addTask(XTask{ XTASK_BLEND,{ a } });
	}

	if (isMerge) {
		double h2 = XVideoThread::Get()->height2;
		double h1 = XVideoThread::Get()->height;
		int w = XVideoThread::Get()->width2 * (h2 / h1);
		XFilter::Get()->addTask(XTask{ XTASK_MERGE });
		ui.width->setValue(XVideoThread::Get()->width + w);
		ui.height->setValue(h1);
		//ui.width->setValue();
	}
}
void XVideoUI::exportVideo()
{
	if (isExport) {
		//ֹͣ����
		XVideoThread::Get()->stopSave();
		isExport = false;
		ui.exportButton->setText("start export");
		return;
	}
	//��ʼ����
	QString name = QFileDialog::getSaveFileName(this,"save","out1.avi");
	int w = ui.width->value();
	int h = ui.height->value();
	if (name.isEmpty())
		return;
	std::string filename = name.toLocal8Bit().data();
	if (XVideoThread::Get()->startSave(filename,w,h,isColor)) {
		isExport = true;
		ui.exportButton->setText("stop export");
	}
}

//�ۣ���Ƶ��������ʱ������Ϣ
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

void XVideoUI::mark()
{
	isMark = false;
	isBlend = false;
	isMerge = false;
	QString name = QFileDialog::getOpenFileName(this, "select image:");
	if (name.isEmpty())
		return;
	std::string file = name.toLocal8Bit().data();
	cv::Mat mark = cv::imread(file);
	if (mark.empty())
		return;
	XVideoThread::Get()->setMark(mark);
	isMark = true;
}

void XVideoUI::blend()
{
	isMark = false;
	isBlend = false;
	isMerge = false;
	QString name = QFileDialog::getOpenFileName(this, "select video:");
	if (name.isEmpty())
		return;
	std::string file = name.toLocal8Bit().data();
	isBlend = XVideoThread::Get()->open2(file);
}

void XVideoUI::merge()
{
	isMark = false;
	isBlend = false;
	isMerge = false;
	QString name = QFileDialog::getOpenFileName(this, "select video:");
	if (name.isEmpty())
		return;
	std::string file = name.toLocal8Bit().data();
	isMerge = XVideoThread::Get()->open2(file);
}
