#pragma once
 
#include<opencv2\/core.hpp>
class XImagePro 
{
 

public:

	//����ԭͼ������������
	///@para mat1 cv::Mat ԭͼ1 0-100
	///@para mat2 cv::Mat ԭͼ2 1.0-3.0
	void set(cv::Mat mat1,cv::Mat mat2);

	//��ȡ������Ľ��
	cv::Mat Get() {
		return des;
	}

	//�������ȺͶԱȶ�
	///@para bright double ���� 0-100
	///@para contrast double �Աȶ� 1.0-3.0
	void gain(double bright, double contrast);

	XImagePro();

	~XImagePro();
private:
	//ԭͼ
	cv::Mat src1, src2;

	//Ŀ��ͼ
	cv::Mat des;
};
