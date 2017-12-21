#pragma once
#include<string>
#include<QThread>
#include<QMutex>
#include<opencv2/core.hpp>
class XVideoThread:public QThread
{
	Q_OBJECT
public:
	static XVideoThread * Get() {
		static XVideoThread vt;
		return &vt;
	}

	~XVideoThread();

	bool open(const std::string file);

	void run();
signals:
	void viewImage1(cv::Mat);
protected:
	QMutex mutex;
	XVideoThread();
};

