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

	void play() {
		mutex.lock();
		isPlay = true;
		mutex.unlock();
	}

	void pause() {
		mutex.lock();
		isPlay = false;
		mutex.unlock();
	}

	double getPos();//返回当前播放的位置

	//视频跳转
	//@para frame int 帧位置
	bool seek(int frame);

	bool seek(double pos);

	//开始保存视频
	bool startSave(const std::string filename, int width=0, int height=0);

	//停止保存视频，写入视频帧的索引
	void stopSave();

	void run();

signals:
	void viewImage1(cv::Mat);

	void viewDes(cv::Mat);

	void saveEnd();
protected:
	//是否开始写视频
	bool isWrite = false;
	bool isPlay = false;
	QMutex mutex;
	XVideoThread();
};

