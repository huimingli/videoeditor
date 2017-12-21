#pragma once

#include <QObject>
#include<vector>
#include<opencv2/core.hpp>
enum XTaskType {
	XTASK_NONE,
	XTASK_GAIN    //亮度对比度调整
};
struct XTask {
	XTaskType type;
	std::vector<double> para;
};
class XFilter  
{
 

public:
	virtual cv::Mat filter(cv::Mat mat1,cv::Mat mat2) = 0;
	virtual void addTask(XTask task) = 0;
	virtual void clear() = 0;
	static XFilter * Get();

	virtual ~XFilter();
protected:
	XFilter();
};
