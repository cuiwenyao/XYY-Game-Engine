#pragma once

#include "./SceneContent.h"
#include "../Drive/GlobalDriver/GlobalDriver.h"
#include "../Drive/GlobalDriver/GlobalLightRendDriver.h"
#include "../Drive/GlobalDriver/GlobalIODriver.h"
#include "../Drive/GlobalDriver/GlobalSyncDriver.h"
#include "../Drive/GlobalDriver/GlobalLogicDriver.h"

#include "../Resource/Window.h";

class XYY_Scene
{
public:
	XYY_Window * win;						// ����������Թ���һ�����ڣ�����ʹ��ָ�� 

	XYY_SceneContent * sc;					// �������ݣ��������ݵ�ʵ�� ������ ����֮�� �� һ����������Ҳ���ܱ������������
	//std::vector<XYY_GlobalDriver *> gd;		// ȫ������ 
	// ȫ������ʹ�ö�̬��ʽ���� �ǳ��鷳 �� ���Կ���ʹ�þ�̬����
	XYY_GlobalLightRendDriver * gd_lightrend;
	XYY_GlobalIODriver        * gd_io;
	XYY_GlobalSyncDriver      * gd_sync;
	XYY_GlobalLogicDriver     * gd_logic;
	
	XYY_Scene(XYY_Window * win, XYY_SceneContent * sc);
	XYY_Scene();						

	void run();								// ���иó���

	// xihang:��������� ���Կ��� �ֿ����õ� ͬ���� �� ������ ��
	// ���ڻص�������Ӧ�ٷ�������������������ʣ�
	static float currenttime;			//��ǰʱ��
	static float lasttime;				//�ϴ�ͬ��ʱ��
	static float deltatime;				//ʱ���
	static float targetfps;				//Ŀ��֡��
	static float currentfps;			//��ǰ֡��
	static float targetframetime;		//Ŀ��֡ʱ��
	static float currentframetime;		//��ǰ֡ʱ��
	static float mouselastX;			//��������
	static float mouselastY;			//���������
	static bool firstMouse;				//����Ƿ��ǵ�һ��

	static void window_seticon_callback(const std::string& iconpath);
	static void window_framebuffer_size_callback(GLFWwindow* window, int width, int height);
	static void window_mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void window_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void window_mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void window_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

};



