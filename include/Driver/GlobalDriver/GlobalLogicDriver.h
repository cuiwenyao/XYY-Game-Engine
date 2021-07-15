#pragma once

#include "./GlobalDriver.h"

/*
	XYY_GlobalLogicDriver 为 全局游戏逻辑类
*/

class   XYY_GlobalLogicDriver : XYY_GlobalDriver
{
public:
	void init();
	void run(XYY_SceneContent * sc);

};