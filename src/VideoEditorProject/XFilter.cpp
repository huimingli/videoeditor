#include "XFilter.h"
#include<QThread>
#include<QMutex>
#include"XImagePro.h"
class CXFilter :public XFilter {
public:
	std::vector<XTask> tasks;
	QMutex mutex;
	cv::Mat filter(cv::Mat mat1, cv::Mat mat2) {
		mutex.lock();
		XImagePro p;
		p.set(mat1, mat2);
		for (int i = 0; i < tasks.size(); i++) {
			switch (tasks[i].type)
			{
			case XTASK_GAIN:
				//���ȶԱȶȵ���
				p.gain(tasks[i].para[0], tasks[i].para[1]);
				break;
			case XTASK_ROTATE_90:
				p.rotate90();
				break;
			case XTASK_ROTATE_180:
				p.rotate180();
				break;
			case XTASK_ROTATE_270:
				p.rotate270();
				break;
			case XTASK_FLIPX:
				p.flipX();
				break;
			case XTASK_FLIPY:
				p.flipY();
				break;
			case XTASK_FLIPXY:
				p.flipXY();
				break;
			case XTASK_RESIZE:
				p.resize(tasks[i].para[0], tasks[i].para[1]);
				break;
			case XTASK_PYDOWN:
				p.pyDown(tasks[i].para[0]);
				break;
			case XTASK_PYUP:
				p.pyUp(tasks[i].para[0]);
				break;
			case XTASK_CLIP:
				p.clip(tasks[i].para[0], tasks[i].para[1], tasks[i].para[2], tasks[i].para[3]);
				break;	
			case XTASK_GRAY:
				p.gray();
				break;
			case XTASK_MARK:
				p.mark(tasks[i].para[0], tasks[i].para[1], tasks[i].para[2]);
				break;
			case XTASK_BLEND:
				p.blend(tasks[i].para[0]);
				break;
			case XTASK_MERGE:
				p.merge();
				break;

			default:
				break;
			}
		}
		cv::Mat re = p.Get();
		mutex.unlock();
		return re;
	}

	void addTask(XTask task) {
		mutex.lock();
		tasks.push_back(task);
		mutex.unlock();
	}

	void clear() {
		mutex.lock();
		tasks.clear();
		mutex.unlock();
	}
};
XFilter::XFilter()
{
}

XFilter * XFilter::Get()
{
	static CXFilter cx;
	return &cx;
}

XFilter::~XFilter()
{
}
