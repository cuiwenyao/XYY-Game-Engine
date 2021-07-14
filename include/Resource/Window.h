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
class   XYY_Window
{
public:
	std::string title = "XYY GAME ENGINE";
	
	bool isFullScreen = false;	// ����δʹ�á�
	int ScreenID = 0;	// ���ж����Ļ��ȫ��ʱ����һ����Ļ�� ����δʹ�á�

	unsigned int scr_windth = 800;
	unsigned int scr_height = 600;

	XYY_Window(unsigned int scr_windth = 800, unsigned int scr_height = 600, unsigned int gl_version_major = 3, unsigned int gl_version_minor = 3);
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

