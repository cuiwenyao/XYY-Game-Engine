#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H

#include "../Component/Scene.h"
#include "../Element/SkyBox.h"
#include <iostream>

static class GlobalVariable
{
public:
	static Camera* camerausing;
	static Scene* sceneusing;
	static Window* windowusing;
	static Shader* defaultobjectshader;
	static Camera* defaultcamera;
	static Window* defaultwindow;
	static GLFWimage icon;
	static SkyBox* skybox;
	static unsigned int objectscount;
	static unsigned int cubescount;
	static unsigned int planescount;
};

#endif // !GLOBALVARIABLE_H