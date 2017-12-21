#include "XVideoWidget.h"
#include<QPainter>
#include<opencv2\imgproc.hpp>
//槽函数
void XVideoWidget::setImage(cv::Mat mat) {
	if (img.isNull()) {
		uchar * buf = new uchar[width()*height() * 3];
		img = QImage(buf, width(), height(), QImage::Format_RGB888);

	}
	cv::Mat des;
	cv::resize(mat, des, cv::Size(img.size().width(), img.size().height()));
	cv::cvtColor(des, des, cv::COLOR_BGR2RGB);
	memcpy(img.bits(), des.data, des.cols*des.rows*des.elemSize());//把矩阵的数据拷贝到QImage中

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
	p.drawImage(QPoint(0, 0), img);//绘制图片
	p.end();
}

XVideoWidget::~XVideoWidget()
{
}
