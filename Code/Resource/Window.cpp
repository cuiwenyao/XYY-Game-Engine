#pragma once
#include "./Window.h"
#include <iostream>

// !!! window类的代码 还需要再优化优化
XYY_Window::XYY_Window(unsigned int scr_windth, unsigned int scr_height, unsigned int gl_version_major, unsigned int gl_version_minor)
{
	this->scr_windth = scr_windth;
	this->scr_height = scr_height;
	this->gl_version_major = gl_version_major;
	this->gl_version_minor = gl_version_minor;

	glfwInit();		// 放这里合适吗？
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, gl_version_major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, gl_version_minor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	this->window = createwindow(scr_windth, scr_height);
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
		//必须有当前window上下文才能初始化GLAD
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
	
	glEnable(GL_DEPTH);

}
GLFWwindow* XYY_Window::getwindow()
{
	return this->window;
}
void XYY_Window::setcontextcurrent()
{
	glfwMakeContextCurrent(this->window);
}

GLFWwindow* XYY_Window::createwindow(unsigned int scr_windth, unsigned int scr_height)
{
	GLFWwindow* window = glfwCreateWindow(scr_windth, scr_height, "window", NULL, NULL);
	return window;
}


