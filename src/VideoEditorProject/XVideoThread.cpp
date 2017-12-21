#include "XVideoThread.h"
#include<iostream>
#include<opencv2\imgcodecs.hpp>
#include<opencv2\imgproc.hpp>
#include<opencv2\highgui.hpp>
using namespace std;
using namespace cv;
//一号视频源
static VideoCapture cap1;
static bool isExit = false;
XVideoThread::XVideoThread()
{
	 
	start();
}


XVideoThread::~XVideoThread()
{
	mutex.lock();
	isExit = true;
	mutex.unlock();
}

bool XVideoThread::open(const std::string file)
{
	mutex.lock();
	int re = cap1.open(file);
	mutex.unlock();
	return re;
}

void XVideoThread::run()
{
	Mat mat1;
	while (true) {
		mutex.lock();
		if (isExit) {
			mutex.unlock();
			break;
		}
		//判断视频是否打开
		if (!cap1.isOpened()) {
			mutex.unlock();
			msleep(5);
			continue;
		}
		//读取一帧视频，解码并颜色转换
		if (!cap1.read(mat1)|| mat1.empty()) {
			mutex.unlock();	 
			msleep(5);
			continue;
		}
		//显示图像
		viewImage1(mat1);
		msleep(40);
		mutex.unlock();		
	}
}

 
