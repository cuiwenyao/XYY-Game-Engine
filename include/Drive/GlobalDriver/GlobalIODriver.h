#pragma once

#include "./GlobalDriver.h"
#include "./GlobalSyncDriver.h"

class __declspec(dllexport) __declspec(dllexport) XYY_GlobalIODriver : public XYY_GlobalDriver
{
public:
	float mouselastX;//��������
	float mouselastY;//���������
	bool firstMouse;//����Ƿ��ǵ�һ��

	XYY_GlobalIODriver();

	void init(XYY_Window * win);

	void run(XYY_SceneContent * sc, XYY_Window * win, XYY_GlobalSyncDriver * sync);



	// ���ڻص�����
	static void window_seticon_callback(const std::string& iconpath);
	static void window_framebuffer_size_callback(GLFWwindow* window, int width, int height);
	static void window_mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void window_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void window_mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void window_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};