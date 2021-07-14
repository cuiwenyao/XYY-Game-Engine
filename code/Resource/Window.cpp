#pragma once
#include "./Window.h"
#include <iostream>

XYY_Window::XYY_Window(unsigned int scr_windth, unsigned int scr_height, unsigned int gl_version_major, unsigned int gl_version_minor)
{
	this->scr_windth = scr_windth;
	this->scr_height = scr_height;
	this->gl_version_major = gl_version_major;
	this->gl_version_minor = gl_version_minor;

	// xihang�����¹���Ϊ ���� ���ڵĹ��� �� ֻ�н����˴��ڲ��ܳ�ʼ��glad��ֻ�г�ʼ����glad����������Դ
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

	// ������һЩ��һЩ���ڳ�ʼ������
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		//�����е�ǰwindow�����Ĳ��ܳ�ʼ�� GLAD
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	glEnable(GL_DEPTH);
}

// ���иô���
void XYY_Window::start()
{
	
}

// �����ô��ڵ�����
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



