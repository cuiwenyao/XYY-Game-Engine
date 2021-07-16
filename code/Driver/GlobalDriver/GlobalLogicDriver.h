#pragma once


#include "./GlobalDriver.h"

/*
	XYY_GlobalLogicDriver Ϊ ȫ����Ϸ�߼���
*/

class __declspec(dllexport) XYY_GlobalLogicDriver : XYY_GlobalDriver
{
public:

	void init(XYY_SceneContent* sc);
	void run(XYY_SceneContent * sc);
	void setInitFunc(  void (*initFunc)(XYY_SceneContent* sc)  );
	void setRunFunc(  void (*runFunc)(XYY_SceneContent* sc)  );

private:
	void (*initFunc)(XYY_SceneContent* sc);						// �ⲿ ��ʼ������
	bool _initFunc = false;

	void (*runFunc)(XYY_SceneContent* sc);  // �ⲿ ���к���
	bool _runFunc = false;

};