#include "XImagePro.h"
#include<opencv2/imgproc.hpp>
#include<opencv2\imgcodecs.hpp>
void XImagePro::gain(double bright, double contrast)
{
	if (des.empty()) return;
	des.convertTo(des, -1, contrast, bright);;
}



void XImagePro::set(cv::Mat mat1, cv::Mat mat2) {
	if (mat1.empty()) return;
	this->src1 = mat1;
	this->src2 = mat2;
	this->src1.copyTo(des);
}

void XImagePro::rotate90()
{
	if (des.empty()) return;
	cv::rotate(des, des, cv::ROTATE_90_CLOCKWISE);
}

void XImagePro::rotate180()
{
	if (des.empty()) return;
	cv::rotate(des, des, cv::ROTATE_180);
}

void XImagePro::rotate270()
{
	if (des.empty()) return;
	cv::rotate(des, des, cv::ROTATE_90_COUNTERCLOCKWISE);
}

//×óÓÒ¾µÏñ
void XImagePro::flipX()
{
	if (des.empty()) return;
	cv::flip(des, des, 0);
}

//ÉÏÏÂ¾µÏñ
void XImagePro::flipY()
{
	if (des.empty()) return;
	cv::flip(des, des, 1);
}

//ÉÏÏÂ×óÓÒ¾µÏñ
void XImagePro::flipXY()
{
	if (des.empty()) return;
	cv::flip(des, des, -1);
}

void XImagePro::resize(int width, int height)
{
	if (des.empty()) return;
	cv::resize(des, des, cv::Size(width, height));
}

void XImagePro::pyDown(int count)
{
	if (des.empty()) return;
	for (int i = 0; i < count; i++) {
		cv::pyrDown(des, des);
	}
}

void XImagePro::pyUp(int count)
{
	if (des.empty()) return;
	for (int i = 0; i < count; i++) {
		cv::pyrUp(des, des);
	}
}

void XImagePro::clip(int x, int y, int w, int h)
{
	if (des.empty()) return;
	if (x < 0 || y < 0 || w <= 0 || h <= 0)
		return;
	if (x > des.cols || y > des.rows)
		return;
	des = des(cv::Rect(x, y, w, h));
}

void XImagePro::gray()
{
	if (des.empty()) return;
	cv::cvtColor(des, des, cv::COLOR_BGR2GRAY);
}

void XImagePro::mark(int x, int y, double a)
{
	if (des.empty()) return;
	if (src2.empty()) return;//Ã»ÓÐË®Ó¡Í¼Æ¬
	cv::Mat rol = des(cv::Rect(x, y, src2.cols, src2.rows));
	cv::addWeighted(src2, a, rol, 1 - a, 0,rol);
}

void XImagePro::blend(double alpha)
{
	if (des.empty()) return;
	if (src2.empty()) return;
	if (src2.size() != des.size()) {
		cv::resize(src2, src2, des.size());
	}
	cv::addWeighted(src2, alpha, des, 1 - alpha, 0, des);
}

void XImagePro::merge()
{
	if (des.empty()) return;
	if (src2.empty()) return;
	if (src2.size() != des.size()) {
		int w = src2.cols * ((double)src2.rows / (double)des.rows);
		cv::resize(src2, src2, cv::Size(w,des.rows));
	}
	int dw = des.cols + src2.cols;
	int dh = des.rows;
	des = cv::Mat(cv::Size(dw, dh), src1.type());
	cv::Mat r1 = des(cv::Rect(0, 0, src1.cols, dh));
	cv::Mat r2 = des(cv::Rect(src1.cols, 0, src2.cols, dh));
	src1.copyTo(r1);
	src2.copyTo(r2);
}

XImagePro::XImagePro()
{
}

XImagePro::~XImagePro()
{
}
