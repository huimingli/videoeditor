#pragma once
#include<string>
class XVideoThread 
{
public:
	static XVideoThread * Get() {
		static XVideoThread vt;
		return &vt;
	}

	~XVideoThread();

	bool open(const std::string file);

	void operator()() const;
protected:
	XVideoThread();
};

