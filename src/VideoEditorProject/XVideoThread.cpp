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

static VideoWriter vw;
 
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
	width = cap1.get(CAP_PROP_FRAME_WIDTH);
	height = cap1.get(CAP_PROP_FRAME_HEIGHT);
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

bool XVideoThread::startSave(const std::string filename, int width, int height)
{
	cout << "startSave export int" << endl;
	seek(0);
	mutex.lock();
	if (!cap1.isOpened()) {
		mutex.unlock();
		return false;
	}
	if (width <= 0)
		width = cap1.get(CAP_PROP_FRAME_WIDTH);
	if (height <= 0)
		height = cap1.get(CAP_PROP_FRAME_HEIGHT);
	vw.open(filename, 
		VideoWriter::fourcc('X', '2', '6', '4'),
		fps,Size(width,height));
	if (!vw.isOpened()) {
		cout << "start save failed" << endl;
	 }
	isWrite = true;
	mutex.unlock();
	return true;
}

void XVideoThread::stopSave()
{
	cout << "stopSave export int" << endl;
	mutex.lock();
	vw.release();
	isWrite = false;
	mutex.unlock();
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

		if (!isPlay) {
			mutex.unlock();
			msleep(5);
			continue;
		}
		//读取一帧视频，解码并颜色转换
		if (!cap1.read(mat1)|| mat1.empty()) {
			mutex.unlock();	 
			if (isWrite) {//导出结束
				stopSave();
				saveEnd();
			}
			msleep(5);
			continue;
		}
		//显示图像1
		if (!isWrite)
		    viewImage1(mat1);
		//通过过滤器处理视频
		Mat des = XFilter::Get()->filter(mat1, Mat());
		//把结果显示出来
		if (!isWrite)
		    viewDes(des);
		int s = 0;
		s = 1000 / fps;
		if (isWrite) {
			s = 1;
			vw.write(des);
		}
	 
		msleep(s);
		mutex.unlock();		
	}
}

 
