#pragma once

#include <QObject>
#include<qopenglwidget.h>
class XVideoWidget : public QOpenGLWidget
{
	Q_OBJECT

public:
	XVideoWidget(QWidget *p);
	void paintEvent(QPaintEvent * e);
	virtual ~XVideoWidget();
};
