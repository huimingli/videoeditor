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
	//�������϶�
	void setPos(int pos);
	//���ù�����
	void set();

	void exportVideo();

	//��������
	void exportEnd();

	//��Ƶ����
	void play();

	//��Ƶ��ͣ
	void pause();
private:
	Ui::XVideoUIClass ui;
};
