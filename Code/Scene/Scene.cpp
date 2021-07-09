#include "./Scene.h"
#include "../Resource/Window.h"
#include "../Drive/GlobalDriver/GlobalLightRendDriver.h"


XYY_Scene::XYY_Scene( XYY_Window * _win , XYY_SceneContent * _sc )
{
	this->win = _win;	// 窗口初始化
	this->sc  = _sc;		// 场景内容初始化	
	this->win->getwindow();

	// 创建全局驱动
	gd_lightrend = new XYY_GlobalLightRendDriver();
	gd_io = new XYY_GlobalIODriver();
	gd_sync = new XYY_GlobalSyncDriver();
	gd_logic = new XYY_GlobalLogicDriver();

	// 加入一个默认的 相机
	this->sc->Cameras.push_back(new XYY_CameraElement());
	return;
}
XYY_Scene::XYY_Scene()
{
	XYY_Window * win_ = new XYY_Window(800, 600, 3, 3);
	XYY_SceneContent * sc_ = new XYY_SceneContent();
	win_->getwindow();

	//XYY_Scene(win_, sc_);
	this->win = win_;	// 窗口初始化
	this->sc = sc_;		// 场景内容初始化	
	this->win->getwindow();

	// 创建全局驱动
	//this->gd.push_back(new XYY_GlobalLightRendDriver());	// 加入一个默认的 全局光照渲染驱动
	gd_lightrend = new XYY_GlobalLightRendDriver();
	gd_io = new XYY_GlobalIODriver();
	gd_sync = new XYY_GlobalSyncDriver();
	gd_logic = new XYY_GlobalLogicDriver();
	
	// 加入一个默认的 相机
	this->sc->Cameras.push_back(new XYY_CameraElement());	
	
	return;
}


void XYY_Scene::run()
{
	//注册回调函数
	//回调函数用在全局控制上面   日后写全局驱动的话，将全局的回调写上去。
	//对于普通物体的IO控制，就不太需要回调函数了。
	//glfwSetFramebufferSizeCallback(win->getwindow(), window_framebuffer_size_callback );
	//glfwSetCursorPosCallback(win->getwindow(), window_mouse_callback);
	//glfwSetScrollCallback(win->getwindow(), window_scroll_callback);
	//glfwSetMouseButtonCallback(win->getwindow(),window_mouse_button_callback);
	glfwSetKeyCallback(win->getwindow(), window_key_callback);
	//std::cout << "成功注册回调函数" << std::endl;

	// 完成各个全局驱动的初始化工作
	gd_sync->init();
	gd_io->init();
	gd_lightrend->init();
	gd_logic->init();

	while ( !glfwWindowShouldClose( win->getwindow() ) )
	{
		//  清除场景信息 与 设置窗口    修改建议：这部分内容建议也 封装到窗口中间 ， 使实现更自由一些
		glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);


		// 调用该场景下的所有全局驱动
		// 这里可以调用到 子类的 run() 吗？
		// ！！！由于C++的特性，这里没有办法以统一的形式调用每个子类的run函数，只能做类型转换后再调用 ， 后面看看怎么改合适
		// for (int i = 0; i < gd.size(); ++i) static_cast<XYY_GlobalLightRendDriver *>(gd[i])->run( sc );
		gd_sync->run();
		gd_io->run(sc,win,gd_sync);
		gd_lightrend->run(sc);
		gd_logic->run(sc);

		// 更新窗口信息	修改建议：这部分内容建议也 封装到窗口中间 ， 使实现更自由一些
		glfwSwapBuffers( win->getwindow() );
		glfwPollEvents();
	}

	// terminate 放这里合适吗？
	glfwTerminate();
}


void XYY_Scene::window_seticon_callback(const std::string& iconpath)
{
	//设置应用图标
	// xihang：可以参考_XYY.cpp中的原来的回调函数实现一个icon资源类
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

	// xihang:相机必须用 回调函数实现吗 ， 考虑直接使用IO控制实现
	// 修改当前相机，后面可以改为调度全局IO控制
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