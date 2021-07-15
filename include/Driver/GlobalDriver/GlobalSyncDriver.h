#pragma once

#include "./GlobalDriver.h"

class   XYY_GlobalSyncDriver : public XYY_GlobalDriver
{
public:
	float currenttime;			// ��ǰʱ��
	float lasttime;				// �ϴ�ͬ��ʱ��
	float deltatime;			// ʱ���
	float targetfps;			// Ŀ��֡��
	float currentfps;			// ��ǰ֡��
	float targetframetime;		// Ŀ��֡ʱ��
	float currentframetime;		// ��ǰ֡ʱ��
	
	XYY_GlobalSyncDriver();
	void init();
	void run();

private:
	void controlFpsWait();		// ֡�ʿ�����ʾ �� ��δʵ��

};