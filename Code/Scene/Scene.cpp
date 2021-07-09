#include "./Scene.h"
#include "../Resource/Window.h"
#include "../Drive/GlobalDriver/GlobalLightRendDriver.h"


XYY_Scene::XYY_Scene( XYY_Window * _win , XYY_SceneContent * _sc )
{
	this->win = _win;	// ���ڳ�ʼ��
	this->sc  = _sc;		// �������ݳ�ʼ��	
	this->win->getwindow();

	// ����ȫ������
	gd_lightrend = new XYY_GlobalLightRendDriver();
	gd_io = new XYY_GlobalIODriver();
	gd_sync = new XYY_GlobalSyncDriver();
	gd_logic = new XYY_GlobalLogicDriver();

	// ����һ��Ĭ�ϵ� ���
	this->sc->Cameras.push_back(new XYY_CameraElement());
	return;
}
XYY_Scene::XYY_Scene()
{
	XYY_Window * win_ = new XYY_Window(800, 600, 3, 3);
	XYY_SceneContent * sc_ = new XYY_SceneContent();
	win_->getwindow();

	//XYY_Scene(win_, sc_);
	this->win = win_;	// ���ڳ�ʼ��
	this->sc = sc_;		// �������ݳ�ʼ��	
	this->win->getwindow();

	// ����ȫ������
	//this->gd.push_back(new XYY_GlobalLightRendDriver());	// ����һ��Ĭ�ϵ� ȫ�ֹ�����Ⱦ����
	gd_lightrend = new XYY_GlobalLightRendDriver();
	gd_io = new XYY_GlobalIODriver();
	gd_sync = new XYY_GlobalSyncDriver();
	gd_logic = new XYY_GlobalLogicDriver();
	
	// ����һ��Ĭ�ϵ� ���
	this->sc->Cameras.push_back(new XYY_CameraElement());	
	
	return;
}


void XYY_Scene::run()
{
	//ע��ص�����
	//�ص���������ȫ�ֿ�������   �պ�дȫ�������Ļ�����ȫ�ֵĻص�д��ȥ��
	//������ͨ�����IO���ƣ��Ͳ�̫��Ҫ�ص������ˡ�
	//glfwSetFramebufferSizeCallback(win->getwindow(), window_framebuffer_size_callback );
	//glfwSetCursorPosCallback(win->getwindow(), window_mouse_callback);
	//glfwSetScrollCallback(win->getwindow(), window_scroll_callback);
	//glfwSetMouseButtonCallback(win->getwindow(),window_mouse_button_callback);
	glfwSetKeyCallback(win->getwindow(), window_key_callback);
	//std::cout << "�ɹ�ע��ص�����" << std::endl;

	// ��ɸ���ȫ�������ĳ�ʼ������
	gd_sync->init();
	gd_io->init();
	gd_lightrend->init();
	gd_logic->init();

	while ( !glfwWindowShouldClose( win->getwindow() ) )
	{
		//  ���������Ϣ �� ���ô���    �޸Ľ��飺�ⲿ�����ݽ���Ҳ ��װ�������м� �� ʹʵ�ָ�����һЩ
		glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);


		// ���øó����µ�����ȫ������
		// ������Ե��õ� ����� run() ��
		// ����������C++�����ԣ�����û�а취��ͳһ����ʽ����ÿ�������run������ֻ��������ת�����ٵ��� �� ���濴����ô�ĺ���
		// for (int i = 0; i < gd.size(); ++i) static_cast<XYY_GlobalLightRendDriver *>(gd[i])->run( sc );
		gd_sync->run();
		gd_io->run(sc,win,gd_sync);
		gd_lightrend->run(sc);
		gd_logic->run(sc);

		// ���´�����Ϣ	�޸Ľ��飺�ⲿ�����ݽ���Ҳ ��װ�������м� �� ʹʵ�ָ�����һЩ
		glfwSwapBuffers( win->getwindow() );
		glfwPollEvents();
	}

	// terminate �����������
	glfwTerminate();
}


void XYY_Scene::window_seticon_callback(const std::string& iconpath)
{
	//����Ӧ��ͼ��
	// xihang�����Բο�_XYY.cpp�е�ԭ���Ļص�����ʵ��һ��icon��Դ��
	return;
}
void XYY_Scene::window_framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// glViewport(0, 0, width, height);
}

void XYY_Scene::window_mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	/*
	std::cout << "mouse_callback" << std::endl;
	
	if (firstMouse == true)
	{
		//xpos = SCR_WIDTH / 2.0f;
		//ypos = SCR_HEIGHT / 2.0f;
		mouselastX = xpos;
		mouselastY = ypos;
		firstMouse = false;
	}
	float xoffset = xpos - mouselastX;
	float yoffset = mouselastY - ypos;
	mouselastX = xpos;
	mouselastY = ypos;

	// xihang:��������� �ص�����ʵ���� �� ����ֱ��ʹ��IO����ʵ��
	// �޸ĵ�ǰ�����������Ը�Ϊ����ȫ��IO����
	static_cast<XYY_CameraElement *>(sc->Cameras[0])->ProcessMouseMovement(xoffset, yoffset);
	  */
	
}

void XYY_Scene::window_scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	// static_cast<XYY_CameraElement *>(sc->Cameras[0])->ProcessMouseScroll(yoffset);
}

void XYY_Scene::window_mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	/* 
	if (action == GLFW_PRESS) switch (button)
	{
	case GLFW_MOUSE_BUTTON_LEFT:
		std::cout << "GLFW_MOUSE_BUTTON_LEFT" << std::endl;
		break;
	case GLFW_MOUSE_BUTTON_MIDDLE:
		std::cout << "GLFW_MOUSE_BUTTON_MIDDLE" << std::endl;
		break;
	case GLFW_MOUSE_BUTTON_RIGHT:
		//glfwSetWindowShouldClose(GlobalVariable::windowusing->getwindow(), true);
		std::cout << "GLFW_MOUSE_BUTTON_RIGHT" << std::endl;
		break;
	default:
		return;
	}
	 */
	
}

void XYY_Scene::window_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) switch (key)
	{
	case GLFW_KEY_ESCAPE:
		// std::cout << "press GLFW_KEY_ESCAPE" << std::endl;
		glfwSetWindowShouldClose(window, true);
		break;
	default:
		return;
	}
	
}