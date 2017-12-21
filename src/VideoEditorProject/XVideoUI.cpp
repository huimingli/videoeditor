#include "XVideoUI.h"
#include<qfiledialog.h>
#include<string>
#include<qmessagebox.h>
#include"XVideoThread.h"
using namespace std;
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