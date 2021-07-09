/* 
//#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H
#include <iostream>
static class GlobalSync
{
public:
	static float currenttime;//当前时间
	static float lasttime;//上此同步时间
	static float deltatime;//时间差
	static float targetfps;//目标帧率
	static float currentfps;//当前帧率
	static float targetframetime;//目标帧时间
	static float currentframetime;//当前帧时间

	static float mouselastX;//鼠标横坐标
	static float mouselastY;//鼠标纵坐标
	static bool firstMouse;//鼠标是否是第一次
	
	static void update();

};

#endif

 */

