#pragma once
#include "Scene.h"
#include "../Sync/GlobalSync.h"
#include "../Variable/GlobalVariable.h"
#include "../Drive/RendDrive.h"
#include "../Drive/IODrive.h"
#include "../Drive/LightDrive.h"
#include <iostream>

//������Щ��̬����
Window* Scene::window;
Camera* Scene::camera;

Scene::Scene()
{
	//std::cout << "Scene" << std::endl;
	this->window = GlobalVariable::defaultwindow;
	this->camera = GlobalVariable::camerausing;
	GlobalSync::mouselastX = window->scr_windth / 2.0f;
	GlobalSync::mouselastY = window->scr_height / 2.0f;
}
void Scene::run()
{
	LightDrive lightdriver;
	RendDrive render;
	IODrive iodriver;
	while (!glfwWindowShouldClose(window->getwindow()))
	{
		GlobalSync::update();
		glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
		//������պ�
		GlobalVariable::skybox->draw();
		//1. ��������Ԫ�ؽ��л���
		//2. ��������������ؽ�������
		for (int i = 0; i < elementnormal.size(); i++)
		{
			lightdriver.illuminate(elementnormal[i], lightlist);
			render.rend(elementnormal[i]);
			iodriver.IO(elementnormal[i]);
		}
		glfwSwapBuffers(window->getwindow());
		glfwPollEvents();

	}

}

void Scene::addelement(Element* element)
{
	if (element->type == 1)//��ͨ����  ������ͨ����list
	{
		elementnormal.push_back(element);
	}
	else if (element->type == 2)
	{
		eleabnormal.push_back(element);
	}
}

void Scene::addlight(Light* light)
{
	lightlist.push_back(light);
}





