#pragma once

#include "./GlobalDriver.h"

class   XYY_GlobalSyncDriver : public XYY_GlobalDriver
{
public:
	float currenttime;			// 当前时间
	float lasttime;				// 上此同步时间
	float deltatime;			// 时间差
	float targetfps;			// 目标帧率
	float currentfps;			// 当前帧率
	float targetframetime;		// 目标帧时间
	float currentframetime;		// 当前帧时间
	
	XYY_GlobalSyncDriver();
	void init();
	void run();

private:
	void controlFpsWait();		// 帧率控制演示 ， 暂未实现

};