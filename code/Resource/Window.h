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
	bool isFullScreen = true;	// 默认全屏
	int ScreenID = 0;	// 若有多块屏幕，全屏时在哪一块屏幕上 【暂未使用】

	unsigned int scr_windth = SCR_WIDTH;
	unsigned int scr_height = SCR_HEIGHT;

	XYY_Window(unsigned int scr_windth = SCR_WIDTH, unsigned int scr_height = SCR_HEIGHT, unsigned int gl_version_major = 3, unsigned int gl_version_minor = 3);
	GLFWwindow * getwindow();
	void setcontextcurrent();

	void start();	// 运行该窗口
	void end();		// 结束窗口

private:
	unsigned int gl_version_major = 3;	// opengl 主版本号
	unsigned int gl_version_minor = 3;	// opengl 副版本号

	GLFWwindow * window;
};

#endif // !WINDOW_H

