#pragma once
#include "GlobalSync.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

float GlobalSync::currenttime;//当前时间
float GlobalSync::lasttime;//上此同步时间
float GlobalSync::deltatime;//时间差
float GlobalSync::targetfps;//目标帧率
float GlobalSync::currentfps;//当前帧率
float GlobalSync::targetframetime;//目标帧时间
float GlobalSync::currentframetime;//当前帧时间
float GlobalSync::mouselastX;//鼠标横坐标
float GlobalSync::mouselastY;//鼠标纵坐标
bool GlobalSync::firstMouse = true;//鼠标是否是第一次

void GlobalSync::update()
{
	currenttime = glfwGetTime();
	deltatime = currenttime - lasttime;
	currentframetime = deltatime;
	lasttime = currenttime;
	currentfps = 1.0 / deltatime;
}

