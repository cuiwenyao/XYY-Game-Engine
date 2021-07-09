#pragma once

#include "./GlobalDriver.h"
#include "./GlobalSyncDriver.h"

#include "../../Resource/Window.h"

class XYY_GlobalIODriver : public XYY_GlobalDriver
{
public:
	float mouselastX;//鼠标横坐标
	float mouselastY;//鼠标纵坐标
	bool firstMouse;//鼠标是否是第一次

	XYY_GlobalIODriver();

	void init();

	void run(XYY_SceneContent * sc, XYY_Window * win, XYY_GlobalSyncDriver * sync);
};