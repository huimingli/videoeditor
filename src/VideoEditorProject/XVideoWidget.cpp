#include "XVideoWidget.h"
#include<QPainter>
#include<opencv2\imgproc.hpp>
//�ۺ���
void XVideoWidget::setImage(cv::Mat mat) {
	QImage::Format fmt = QImage::Format_RGB888;
	int pixSize = 3;
	if (mat.type() == CV_8UC1) {
		fmt = QImage::Format_Grayscale8;
		pixSize = 1;
	}
	if (img.isNull() || img.format() != fmt) {
		delete img.bits();
		uchar * buf = new uchar[width()*height() * pixSize];
		img = QImage(buf, width(), height(), fmt);

	}
	cv::Mat des;
	cv::resize(mat, des, cv::Size(img.size().width(), img.size().height()));
	if(pixSize > 1)
	cv::cvtColor(des, des, cv::COLOR_BGR2RGB);
	memcpy(img.bits(), des.data, des.cols*des.rows*des.elemSize());//�Ѿ�������ݿ�����QImage��

	update();

}

XVideoWidget::XVideoWidget(QWidget *p)
	: QOpenGLWidget(p)
{
}

void XVideoWidget::paintEvent(QPaintEvent * e)
{
	QPainter p;
	p.begin(this);
	p.drawImage(QPoint(0, 0), img);//����ͼƬ
	p.end();
}

XVideoWidget::~XVideoWidget()
{
}
