#pragma once


#include "./GlobalDriver.h"

/*
	XYY_GlobalLogicDriver Ϊ ȫ����Ϸ�߼���
*/

class __declspec(dllexport) XYY_GlobalLogicDriver : XYY_GlobalDriver
{
public:
	void init();
	void run(XYY_SceneContent * sc);

};