#pragma once
 
#include<opencv2\/core.hpp>
class XImagePro 
{
 

public:

	//设置原图，会清理处理结果
	///@para mat1 cv::Mat 原图1 0-100
	///@para mat2 cv::Mat 原图2 1.0-3.0
	void set(cv::Mat mat1,cv::Mat mat2);

	//获取处理过的结果
	cv::Mat Get() {
		return des;
	}

	//设置亮度和对比度
	///@para bright double 亮度 0-100
	///@para contrast double 对比度 1.0-3.0
	void gain(double bright, double contrast);

	XImagePro();

	~XImagePro();
private:
	//原图
	cv::Mat src1, src2;

	//目标图
	cv::Mat des;
};
