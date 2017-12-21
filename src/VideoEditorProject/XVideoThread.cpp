#include "XVideoThread.h"
#include<iostream>
#include<opencv2\imgcodecs.hpp>
#include<opencv2\imgproc.hpp>
#include<opencv2\highgui.hpp>
#include"XFilter.h"
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
	wait();
}

bool XVideoThread::open(const std::string file)
{
	mutex.lock();
	int re = cap1.open(file);
	mutex.unlock();
	if (!re) {
		return re;
	}
	fps = cap1.get(CAP_PROP_FPS);
	if (fps <= 0) fps = 25;
	return true;
}

double XVideoThread::getPos()
{
	double pos = 0;
	mutex.lock();
	if (!cap1.isOpened()) {
		mutex.unlock();
		return pos;
	}
	double count = cap1.get(CAP_PROP_FRAME_COUNT);
	double cur1 = cap1.get(CAP_PROP_POS_FRAMES);
	if(count>0.001)
	    pos = cur1 / count;
	mutex.unlock();
	return pos;
}

bool XVideoThread::seek(int frame)
{
	mutex.lock();
	if (!cap1.isOpened()) {
		mutex.unlock();
		return false;
	}
	int re = cap1.set(CAP_PROP_POS_FRAMES, frame);
	mutex.unlock();
	return re;
}

bool XVideoThread::seek(double pos)
{
	double count = cap1.get(CAP_PROP_FRAME_COUNT);
	int frame = pos*count;
	return seek(frame);
	 
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
		//显示图像1
		viewImage1(mat1);
		//通过过滤器处理视频
		Mat des = XFilter::Get()->filter(mat1, Mat());
		//把结果显示出来
		viewDes(des);
		int s = 0;
		s = 1000 / fps;
		msleep(s);
		mutex.unlock();		
	}
}

 
