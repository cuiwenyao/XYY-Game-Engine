#include "./GlobalIODriver.h"

XYY_GlobalIODriver::XYY_GlobalIODriver()
{
	firstMouse = true;
	return;
}

void XYY_GlobalIODriver::init(XYY_Window * win)
{
	/*注册回调函数*/
	//回调函数用在全局控制上面   日后写全局驱动的话，将全局的回调写上去。
	//对于普通物体的IO控制，就不太需要回调函数了。
	//glfwSetFramebufferSizeCallback(win->getwindow(), window_framebuffer_size_callback );
	//glfwSetCursorPosCallback(win->getwindow(), window_mouse_callback);
	//glfwSetScrollCallback(win->getwindow(), window_scroll_callback);
	//glfwSetMouseButtonCallback(win->getwindow(),window_mouse_button_callback);
	glfwSetKeyCallback(win->getwindow(), window_key_callback);
	//std::cout << "成功注册回调函数" << std::endl;

	/* 初始化鼠标为第一次操作 */
	firstMouse = true;

	// game init
	if (_initFunc) (*initFunc)();

}

void XYY_GlobalIODriver::run(XYY_SceneContent * sc,XYY_Window * win, XYY_GlobalSyncDriver * sync)
{
	// 键盘
	XYY_CameraElement * nowcra = sc->Cameras[0];
	if (glfwGetKey(win->getwindow(), GLFW_KEY_W) == GLFW_PRESS)
		nowcra->ProcessKeyboard(FORWARD, sync->deltatime);
	if (glfwGetKey(win->getwindow(), GLFW_KEY_S) == GLFW_PRESS)
		nowcra->ProcessKeyboard(BACKWARD, sync->deltatime);
	if (glfwGetKey(win->getwindow(), GLFW_KEY_A) == GLFW_PRESS)
		nowcra->ProcessKeyboard(LEFT, sync->deltatime);
	if (glfwGetKey(win->getwindow(), GLFW_KEY_D) == GLFW_PRESS)
		nowcra->ProcessKeyboard(RIGHT, sync->deltatime);
		// 上下移动
		if (glfwGetKey(win->getwindow(), GLFW_KEY_Q) == GLFW_PRESS)
			nowcra->ProcessKeyboard(DOWN, sync->deltatime);
		if (glfwGetKey(win->getwindow(), GLFW_KEY_E) == GLFW_PRESS)
			nowcra->ProcessKeyboard(UP, sync->deltatime);

		// 加速减速
		if (glfwGetKey(win->getwindow(), GLFW_KEY_F) == GLFW_PRESS)
			nowcra->ProcessKeyboard(F, sync->deltatime);
		if (glfwGetKey(win->getwindow(), GLFW_KEY_G) == GLFW_PRESS)
			nowcra->ProcessKeyboard(G, sync->deltatime);

	
	// 鼠标
	// xihang: 不知道为什么 ， 方向第一次总是 飘走 ，有空解决下
	double xpos, ypos;
	glfwGetCursorPos(win->getwindow(),&xpos,&ypos);
	if (firstMouse == true)
	{
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
	// std::cout << xoffset << ' ' << yoffset << std::endl;
	sc->Cameras[0]->ProcessMouseMovement(xoffset, yoffset);

	// game running
	if (_runFunc) (*runFunc)(sc,win,sync);
	
}

void XYY_GlobalIODriver::setInitFunc(void (*initFunc)())
{
	this->_initFunc = true;
	this->initFunc = initFunc;
}

void XYY_GlobalIODriver::setRunFunc(void (*runFunc)(XYY_SceneContent* sc, XYY_Window* win, XYY_GlobalSyncDriver* sync))
{
	this->_runFunc = true;
	this->runFunc = runFunc;
}



void XYY_GlobalIODriver::window_seticon_callback(const std::string& iconpath)
{
	//设置应用图标
	// xihang：可以参考_XYY.cpp中的原来的回调函数实现一个icon资源类
	return;
}
void XYY_GlobalIODriver::window_framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// glViewport(0, 0, width, height);
}

void XYY_GlobalIODriver::window_mouse_callback(GLFWwindow* window, double xpos, double ypos)
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

void XYY_GlobalIODriver::window_scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	// static_cast<XYY_CameraElement *>(sc->Cameras[0])->ProcessMouseScroll(yoffset);
}

void XYY_GlobalIODriver::window_mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
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

void XYY_GlobalIODriver::window_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
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