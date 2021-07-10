#pragma once

#include "../Drive/GlobalDriver/GlobalDriver.h"
#include "../Drive/GlobalDriver/GlobalLightRendDriver.h"
#include "../Drive/GlobalDriver/GlobalIODriver.h"
#include "../Drive/GlobalDriver/GlobalSyncDriver.h"
#include "../Drive/GlobalDriver/GlobalLogicDriver.h"
#include "../Drive/GlobalDriver/GlobalDebugoutDriver.h"


class __declspec(dllexport) XYY_Scene
{
public:
	XYY_Window * win;						// 多个场景可以共用一个窗口，所以使用指针 

	XYY_SceneContent * sc;					// 场景内容，场景内容的实体 存在于 场景之中 ， 一个场景内容也可能被多个场景公用

	// 全局驱动使用动态方式管理 非常麻烦 ， 所以考虑使用静态管理
	XYY_GlobalLightRendDriver * gd_lightrend;
	XYY_GlobalIODriver		  * gd_io;
	XYY_GlobalSyncDriver      * gd_sync;
	XYY_GlobalLogicDriver     * gd_logic;
	XYY_GlobalDebugoutDriver  * gd_debugout;
	
	XYY_Scene(XYY_Window * win, XYY_SceneContent * sc);
	XYY_Scene();						

	void run();								// 运行该场景

private:
	void initGlobalDriver();				// 建立内置全局驱动

};
