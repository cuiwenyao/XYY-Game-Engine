#ifndef SCENE_H
#define SCENE_H

#include "Window.h"
#include "../Element/Camera.h"
#include "../Element/Object.h"
#include "../Element/Light.h"
#include <vector>
#include <iostream>

const unsigned int scr_windth = 800;
const unsigned int scr_height = 600;

class Scene
{
public:
	static Window* window;
	static Camera* camera;
	std::vector <Element* > elementnormal;//��ͨ����  ��Ⱦ˳��������������������
	std::vector <Element* > eleabnormal;//����ͨ����
	std::vector<Light* > lightlist;//����
	Scene();
	void run();
	void addelement(Element* element);
	void addlight(Light* light);
};


#endif

