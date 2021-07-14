#pragma once
#include "./Element.h"

class __declspec(dllexport) XYY_LightElement : public XYY_Element
{
	/*
		光元素 是一种无形状的 ， 发光的实体， 其做为 发光的一种 基本元素
		用来承载 光局部驱动
	*/
public:
	// std::vector<XYY_LocalDriver *> ld;
	XYY_LocalLightDriver * ld_light;

	XYY_LightElement(int tp = 1);
	void setcolor(glm::vec4 _color_a);
	void setcolor(glm::vec3 _color);

};