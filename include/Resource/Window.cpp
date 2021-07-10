#pragma once
#include "./Window.h"
#include <iostream>

XYY_Window::XYY_Window(unsigned int scr_windth, unsigned int scr_height, unsigned int gl_version_major, unsigned int gl_version_minor)
{
	this->scr_windth = scr_windth;
	this->scr_height = scr_height;
	this->gl_version_major = gl_version_major;
	this->gl_version_minor = gl_version_minor;

	// xihang：以下过程为 建立 窗口的过程 ， 只有建立了窗口才能初始化glad，只有初始化了glad才能载入资源
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, gl_version_major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, gl_version_minor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->window = glfwCreateWindow(scr_windth, scr_height, title.c_str(), NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	this->setcontextcurrent();

	// tell GLFW to capture our mouse
	glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// 下面是一些，一些窗口初始化工作
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		//必须有当前window上下文才能初始化 GLAD
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	glEnable(GL_DEPTH);
}

// 运行该窗口
void XYY_Window::start()
{
	
}

// 结束该窗口的运行
void XYY_Window::end()
{
	glfwTerminate();
}


GLFWwindow* XYY_Window::getwindow()
{
	return this->window;
}

void XYY_Window::setcontextcurrent()
{
	glfwMakeContextCurrent(this->window);
}



