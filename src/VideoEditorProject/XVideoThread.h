#pragma once
#include<string>
#include<QThread>
#include<QMutex>
#include<opencv2/core.hpp>
class XVideoThread:public QThread
{
	Q_OBJECT
public:
	int fps = 0;
	static XVideoThread * Get() {
		static XVideoThread vt;
		return &vt;
	}

	~XVideoThread();

	bool open(const std::string file);

	double getPos();//返回当前播放的位置

	//视频跳转
	//@para frame int 帧位置
	bool seek(int frame);

	bool seek(double pos);

	void run();
signals:
	void viewImage1(cv::Mat);

	void viewDes(cv::Mat);
protected:
	QMutex mutex;
	XVideoThread();
};

