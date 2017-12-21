#include "XVideoUI.h"
#include<qfiledialog.h>
#include<string>
#include<qmessagebox.h>
#include"XVideoThread.h"
#include"XFilter.h"
using namespace std;
static bool pressSlider = false;
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

	QObject::connect(XVideoThread::Get(),//�źŷ����Ķ���
		SIGNAL(viewDes(cv::Mat)),//�ź�
		ui.des,//�۽��յĶ���
		SLOT(setImage(cv::Mat))//��
	);
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
