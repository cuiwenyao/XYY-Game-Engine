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
	std::vector <Element* > elementnormal;//普通物体  渲染顺序有区别所以这样分类
	std::vector <Element* > eleabnormal;//不普通物体
	std::vector<Light* > lightlist;//光照
	Scene();
	void run();
	void addelement(Element* element);
	void addlight(Light* light);
};


#endif

