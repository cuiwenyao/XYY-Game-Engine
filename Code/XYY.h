#ifndef XYY_H
#define XYY_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Component/Scene.h"
#include "Element/Object.h"
#include "Element/Shader.h"
#include "Variable/GlobalVariable.h"
#include "ResManager/ResManager.h"
#include <iostream>

static class XYY
{
public:
	static void Init();
	static void seticon(const std::string& iconpath);
private:
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

};













#endif // !XYY_H




