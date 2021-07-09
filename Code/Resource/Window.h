#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
// Default window values
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const unsigned int GL_VERSION_MAJOR = 3;
const unsigned int GL_VERSION_MINOR = 3;
class XYY_Window
{
public:
	unsigned int scr_windth = 800;
	unsigned int scr_height = 600;
	unsigned int gl_version_major = 3;
	unsigned int gl_version_minor = 3;
	XYY_Window(unsigned int scr_windth = 800, unsigned int scr_height = 600, unsigned int gl_version_major = 3, unsigned int gl_version_minor = 3);
	GLFWwindow * getwindow();
	void setcontextcurrent();
private:
	GLFWwindow * window;
	GLFWwindow * createwindow(unsigned int scr_windth, unsigned int scr_height);
};

#endif // !WINDOW_H

