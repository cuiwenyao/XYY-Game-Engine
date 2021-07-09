#include "./GlobalIODriver.h"

XYY_GlobalIODriver::XYY_GlobalIODriver()
{
	firstMouse = true;
	return;
}

void XYY_GlobalIODriver::init()
{
	firstMouse = true;
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
		xpos = SCR_WIDTH / 2.0f;
		ypos = SCR_HEIGHT / 2.0f;
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
	
	
	
}