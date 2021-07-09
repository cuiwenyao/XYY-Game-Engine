#pragma once

#include "./GlobalDriver.h"
#include "./GlobalSyncDriver.h"

#include "../../Resource/Window.h"

class XYY_GlobalIODriver : public XYY_GlobalDriver
{
public:
	float mouselastX;//��������
	float mouselastY;//���������
	bool firstMouse;//����Ƿ��ǵ�һ��

	XYY_GlobalIODriver();

	void init();

	void run(XYY_SceneContent * sc, XYY_Window * win, XYY_GlobalSyncDriver * sync);
};