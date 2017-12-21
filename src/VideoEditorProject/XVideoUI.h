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
	//»¬¶¯ÌõÍÏ¶¯
	void setPos(int pos);
private:
	Ui::XVideoUIClass ui;
};
