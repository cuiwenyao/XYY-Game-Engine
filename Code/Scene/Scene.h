#pragma once

#include "./SceneContent.h"
#include "../Drive/GlobalDriver/GlobalDriver.h"
#include "../Drive/GlobalDriver/GlobalLightRendDriver.h"
#include "../Drive/GlobalDriver/GlobalIODriver.h"
#include "../Drive/GlobalDriver/GlobalSyncDriver.h"
#include "../Drive/GlobalDriver/GlobalLogicDriver.h"

#include "../Resource/Window.h";

class XYY_Scene
{
public:
	XYY_Window * win;						// 多个场景可以共用一个窗口，所以使用指针 

	XYY_SceneContent * sc;					// 场景内容，场景内容的实体 存在于 场景之中 ， 一个场景内容也可能被多个场景公用
	//std::vector<XYY_GlobalDriver *> gd;		// 全局驱动 
	// 全局驱动使用动态方式管理 非常麻烦 ， 所以考虑使用静态管理
	XYY_GlobalLightRendDriver * gd_lightrend;
	XYY_GlobalIODriver        * gd_io;
	XYY_GlobalSyncDriver      * gd_sync;
	XYY_GlobalLogicDriver     * gd_logic;
	
	XYY_Scene(XYY_Window * win, XYY_SceneContent * sc);
	XYY_Scene();						

	void run();								// 运行该场景

	// xihang:下面的内容 可以考虑 分开放置到 同步类 和 窗口类 中
	// 窗口回调函数（应再分析分析放在哪里更合适）
	static float currenttime;			//当前时间
	static float lasttime;				//上此同步时间
	static float deltatime;				//时间差
	static float targetfps;				//目标帧率
	static float currentfps;			//当前帧率
	static float targetframetime;		//目标帧时间
	static float currentframetime;		//当前帧时间
	static float mouselastX;			//鼠标横坐标
	static float mouselastY;			//鼠标纵坐标
	static bool firstMouse;				//鼠标是否是第一次

	static void window_seticon_callback(const std::string& iconpath);
	static void window_framebuffer_size_callback(GLFWwindow* window, int width, int height);
	static void window_mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void window_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void window_mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void window_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

};



