#pragma once
#include "Window.h"

#include <iostream>


Window::Window(unsigned int scr_windth, unsigned int scr_height, unsigned int gl_version_major, unsigned int gl_version_minor)
{
	this->scr_windth = scr_windth;
	this->scr_height = scr_height;
	this->gl_version_major = gl_version_major;
	this->gl_version_minor = gl_version_minor;
	//glfwInit();
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
}
GLFWwindow* Window::getwindow()
{
	return this->window;
}
void Window::setcontextcurrent()
{
	glfwMakeContextCurrent(this->window);
}
	
GLFWwindow* Window::createwindow(unsigned int scr_windth, unsigned int scr_height)
{

	GLFWwindow* window = glfwCreateWindow(scr_windth, scr_height, "window", NULL, NULL);
	return window;
}


