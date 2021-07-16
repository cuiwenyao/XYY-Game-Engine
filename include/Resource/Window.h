#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
// Default window values
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;
const unsigned int GL_VERSION_MAJOR = 3;
const unsigned int GL_VERSION_MINOR = 3;
class __declspec(dllexport) XYY_Window
{
public:
	std::string title = "XYY GAME ENGINE";
	bool isFullScreen = true;	// Ĭ��ȫ��
	int ScreenID = 0;	// ���ж����Ļ��ȫ��ʱ����һ����Ļ�� ����δʹ�á�

	unsigned int scr_windth = SCR_WIDTH;
	unsigned int scr_height = SCR_HEIGHT;

	XYY_Window(unsigned int scr_windth = SCR_WIDTH, unsigned int scr_height = SCR_HEIGHT, unsigned int gl_version_major = 3, unsigned int gl_version_minor = 3);
	GLFWwindow * getwindow();
	void setcontextcurrent();

	void start();	// ���иô���
	void end();		// ��������

private:
	unsigned int gl_version_major = 3;	// opengl ���汾��
	unsigned int gl_version_minor = 3;	// opengl ���汾��

	GLFWwindow * window;
};

#endif // !WINDOW_H

