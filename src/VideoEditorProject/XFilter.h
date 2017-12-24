#pragma once

#include <QObject>
#include<vector>
#include<opencv2/core.hpp>
enum XTaskType {
	XTASK_NONE,
	XTASK_GAIN,    //���ȶԱȶȵ���
	XTASK_ROTATE_90,
	XTASK_ROTATE_180,
	XTASK_ROTATE_270,
	XTASK_FLIPX,
	XTASK_FLIPY,
	XTASK_FLIPXY,
	XTASK_RESIZE,
	XTASK_PYDOWN,
	XTASK_PYUP,
	XTASK_CLIP
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
