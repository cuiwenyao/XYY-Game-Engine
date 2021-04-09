#pragma once


#include "XYY.h"
#include "Sync/GlobalSync.h"
#include "ResManager/ResManager.h"

void XYY::Init()
{
    glfwInit();
    //init 
    GlobalVariable::defaultwindow = new Window(800, 600, 3, 3);
	GlobalVariable::windowusing = GlobalVariable::defaultwindow;
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        //必须有当前window上下文才能初始化GLAD
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    GlobalVariable::defaultcamera = new Camera(glm::vec3(0.0, 0.0, 1.0));
    GlobalVariable::camerausing = GlobalVariable::defaultcamera;
    GlobalVariable::defaultobjectshader = new Shader("GLSL/object.vert", "GLSL/object.frag");
	GlobalVariable::skybox = new SkyBox("resources/textures/skybox");
	 
    //注册回调函数
	//回调函数用在全局控制上面   日后写全局驱动的话，将全局的回调写上去。
	//对于普通物体的IO控制，就不太需要回调函数了。
	//全局驱动用回调挺好的。
	glfwSetFramebufferSizeCallback(GlobalVariable::windowusing->getwindow(), framebuffer_size_callback);
	glfwSetCursorPosCallback(GlobalVariable::windowusing->getwindow(), mouse_callback);
	glfwSetScrollCallback(GlobalVariable::windowusing->getwindow(), scroll_callback);
	glfwSetMouseButtonCallback(GlobalVariable::windowusing->getwindow(), mouse_button_callback);
	glfwSetKeyCallback(GlobalVariable::windowusing->getwindow(), key_callback);
	std::cout << "成功注册回调函数" << std::endl;

	glEnable(GL_DEPTH);

	//设置应用图标
	XYY::seticon("resources/image/XYY.jpg");

}

void XYY::seticon(const std::string& iconpath)
{
	ResManager::seticon(iconpath);
}
void XYY::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void XYY::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	//std::cout << "mouse_callback" << std::endl;
	if (GlobalSync::firstMouse == true)
	{
		//xpos = SCR_WIDTH / 2.0f;
		//ypos = SCR_HEIGHT / 2.0f;
		GlobalSync::mouselastX = xpos;
		GlobalSync::mouselastY = ypos;
		GlobalSync::firstMouse = false;
	}
	float xoffset = xpos - GlobalSync::mouselastX;
	float yoffset = GlobalSync::mouselastY - ypos; 
	GlobalSync::mouselastX = xpos;
	GlobalSync::mouselastY = ypos;
	GlobalVariable::camerausing->ProcessMouseMovement(xoffset, yoffset);

}

void XYY::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	GlobalVariable::camerausing->ProcessMouseScroll(yoffset);
}

void XYY::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
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
}

void XYY::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) switch (key)
	{
	case GLFW_KEY_ESCAPE:
		std::cout << "press GLFW_KEY_ESCAPE" << std::endl;
		glfwSetWindowShouldClose(GlobalVariable::windowusing->getwindow(), true);
		break;
	default:
		return;
	}
}




