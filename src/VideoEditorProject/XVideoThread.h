#pragma once
#include<string>
#include<QThread>
#include<QMutex>
#include<opencv2/core.hpp>
class XVideoThread:public QThread
{
	Q_OBJECT
public:
	int fps = 0;
	static XVideoThread * Get() {
		static XVideoThread vt;
		return &vt;
	}

	~XVideoThread();

	bool open(const std::string file);

	double getPos();//���ص�ǰ���ŵ�λ��

	//��Ƶ��ת
	//@para frame int ֡λ��
	bool seek(int frame);

	bool seek(double pos);

	//��ʼ������Ƶ
	bool startSave(const std::string filename, int width=0, int height=0);

	//ֹͣ������Ƶ��д����Ƶ֡������
	void stopSave();

	void run();

	void saveEnd();
signals:
	void viewImage1(cv::Mat);

	void viewDes(cv::Mat);
protected:
	//�Ƿ�ʼд��Ƶ
	bool isWrite = false;
	QMutex mutex;
	XVideoThread();
};

