#pragma once

#include <QObject>
#include<qopenglwidget.h>
#include<opencv2/core.hpp>
class XVideoWidget : public QOpenGLWidget
{
	Q_OBJECT

public:
	XVideoWidget(QWidget *p);
	void paintEvent(QPaintEvent * e);
	virtual ~XVideoWidget();
public slots:
    void setImage(cv::Mat mat);
protected:
	QImage img;
};
