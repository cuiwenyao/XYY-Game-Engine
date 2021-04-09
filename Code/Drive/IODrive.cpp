#pragma once
#include "IODrive.h"
#include <GLFW/glfw3.h>
#include "../Variable/GlobalVariable.h"
#include "../Sync/GlobalSync.h"
#include "../Element/Element.h"
//�����������룬�����������С�
void IODrive::IO(Element* element)
{
	keyInput(element);
	mouseInput(element);
	scrollInput(element);
}

void IODrive::keyInput(Element* element)
{	
	if (glfwGetKey(GlobalVariable::windowusing->getwindow(), GLFW_KEY_W) == GLFW_PRESS)
		GlobalVariable::camerausing->ProcessKeyboard(FORWARD, GlobalSync::deltatime);
	if (glfwGetKey(GlobalVariable::windowusing->getwindow(), GLFW_KEY_S) == GLFW_PRESS)
		GlobalVariable::camerausing->ProcessKeyboard(BACKWARD, GlobalSync::deltatime);
	if (glfwGetKey(GlobalVariable::windowusing->getwindow(), GLFW_KEY_A) == GLFW_PRESS)
		GlobalVariable::camerausing->ProcessKeyboard(LEFT, GlobalSync::deltatime);
	if (glfwGetKey(GlobalVariable::windowusing->getwindow(), GLFW_KEY_D) == GLFW_PRESS)
		GlobalVariable::camerausing->ProcessKeyboard(RIGHT, GlobalSync::deltatime);
	if (element->id == 1)
	{
		//����T��֮�󣬶�ģ�ͽ��иı�
		if (glfwGetKey(GlobalVariable::windowusing->getwindow(), GLFW_KEY_T) == GLFW_PRESS)
		{
			element->Stretch(glm::vec3(0.999, 0.999, 0.999));
		}
		if (glfwGetKey(GlobalVariable::windowusing->getwindow(), GLFW_KEY_Y) == GLFW_PRESS)
		{
			element->Stretch(glm::vec3(1.001, 1.001, 1.001));
		}
		if (glfwGetKey(GlobalVariable::windowusing->getwindow(), GLFW_KEY_U) == GLFW_PRESS)
		{
			element->setposition(glm::vec3(0, 0, 0));
		}
		if (glfwGetKey(GlobalVariable::windowusing->getwindow(), GLFW_KEY_Q) == GLFW_PRESS)
		{
			element->move(glm::vec3(-(element->speed * GlobalSync::deltatime)/element->scale.x, 0, 0));
		}
		if (glfwGetKey(GlobalVariable::windowusing->getwindow(), GLFW_KEY_E) == GLFW_PRESS)
		{
			element->move(glm::vec3((element->speed * GlobalSync::deltatime)/element->scale.x, 0, 0));
		}
		if (glfwGetKey(GlobalVariable::windowusing->getwindow(), GLFW_KEY_Z) == GLFW_PRESS)
		{
			element->move(glm::vec3(0, 0, -(element->speed * GlobalSync::deltatime) / element->scale.z));
		}
		if (glfwGetKey(GlobalVariable::windowusing->getwindow(), GLFW_KEY_C) == GLFW_PRESS)
		{
			element->move(glm::vec3(0, 0, (element->speed * GlobalSync::deltatime) / element->scale.z));
		}

	}

}
void IODrive::mouseInput(Element* element)
{
	//����ĳ������������ﳯ��
	if (glfwGetMouseButton(GlobalVariable::windowusing->getwindow(), GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
		std::cout << "GLFW_MOUSE_BUTTON_RIGHT" << std::endl;

}
void IODrive::scrollInput(Element* element)
{
	;//�������ĳ���
}