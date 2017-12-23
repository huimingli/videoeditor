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
	//�ԱȶȺ����ȵ�����
	if (ui.bright->value() > 0 ||
		ui.contrast->value() >1) {
		XFilter::Get()->addTask(XTask{ XTASK_GAIN,{(double)(ui.bright->value()),ui.contrast->value()} });
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
	if (name.isEmpty())
		return;
	std::string filename = name.toLocal8Bit().data();
	if (XVideoThread::Get()->startSave(filename)) {
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
