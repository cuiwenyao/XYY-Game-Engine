#pragma once


#include "./GlobalDriver.h"

/*
	XYY_GlobalLogicDriver 为 全局游戏逻辑类
*/

class __declspec(dllexport) XYY_GlobalLogicDriver : XYY_GlobalDriver
{
public:

	void init(XYY_SceneContent* sc);
	void run(XYY_SceneContent * sc);
	void setInitFunc(  void (*initFunc)(XYY_SceneContent* sc)  );
	void setRunFunc(  void (*runFunc)(XYY_SceneContent* sc)  );

private:
	void (*initFunc)(XYY_SceneContent* sc);						// 外部 初始化函数
	bool _initFunc = false;

	void (*runFunc)(XYY_SceneContent* sc);  // 外部 运行函数
	bool _runFunc = false;

};