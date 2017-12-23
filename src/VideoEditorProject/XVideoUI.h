#pragma once

#include <QtWidgets/QWidget>
#include "ui_XVideoUI.h"

class XVideoUI : public QWidget
{
	Q_OBJECT

public:
	XVideoUI(QWidget *parent = Q_NULLPTR);
	void timerEvent(QTimerEvent *e);
public slots:
	void open();
	void sliderPress();
	void sliderRelease();
	//滑动条拖动
	void setPos(int pos);
	//设置过滤器
	void set();

	void exportVideo();

	//导出结束
	void exportEnd();
private:
	Ui::XVideoUIClass ui;
};
