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
	int width = 0;
	int height = 0;
	int width2 = 0;
	int height2 = 0;
	static XVideoThread * Get() {
		static XVideoThread vt;
		return &vt;
	}

	~XVideoThread();

	//��һ����Ƶ�ļ�
	bool open(const std::string file);

	//��һ����ƵԴ�ļ�
	bool open2(const std::string file);

	void play() {
		mutex.lock();
		isPlay = true;
		mutex.unlock();
	}

	void pause() {
		mutex.lock();
		isPlay = false;
		mutex.unlock();
	}

	double getPos();//���ص�ǰ���ŵ�λ��

	//��Ƶ��ת
	//@para frame int ֡λ��
	bool seek(int frame);

	bool seek(double pos);

	//��ʼ������Ƶ
	bool startSave(const std::string filename, int width=0, int height=0,bool isColor = true);

	//ֹͣ������Ƶ��д����Ƶ֡������
	void stopSave();

	//���ˮӡ
	//todo ˮӡ�ֱ��ʱ���Ƶ��
	void setMark(cv::Mat mark);

	void run();

signals:
	void viewImage1(cv::Mat);

	void viewImage2(cv::Mat);

	void viewDes(cv::Mat);

	void saveEnd();
protected:
	//�Ƿ�ʼд��Ƶ
	bool isWrite = false;
	bool isPlay = false;
	QMutex mutex;
	cv::Mat mark;
	XVideoThread();
};

