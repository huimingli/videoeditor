#include "XVideoThread.h"
#include<iostream>
#include<opencv2\imgcodecs.hpp>
#include<opencv2\imgproc.hpp>
#include<opencv2\highgui.hpp>
using namespace std;
using namespace cv;
//“ª∫≈ ”∆µ‘¥
static VideoCapture cap1;

XVideoThread::XVideoThread()
{
}


XVideoThread::~XVideoThread()
{
}

bool XVideoThread::open(const std::string file)
{
	std::cout << file << std::endl;
	int re = cap1.open(file);
	std::cout << re << std::endl;
	Mat frame;
	while (true) {
		cap1 >> frame;
		if (frame.empty()) {
			break;
		}
	}
	return re;
}

void XVideoThread::operator()() const
{
}
