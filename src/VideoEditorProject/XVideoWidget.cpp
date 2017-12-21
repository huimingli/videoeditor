#include "XVideoWidget.h"
#include<QPainter>
#include<opencv2\imgproc.hpp>
//�ۺ���
void XVideoWidget::setImage(cv::Mat mat) {
	if (img.isNull()) {
		uchar * buf = new uchar[width()*height() * 3];
		img = QImage(buf, width(), height(), QImage::Format_RGB888);

	}
	cv::Mat des;
	cv::resize(mat, des, cv::Size(img.size().width(), img.size().height()));
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
