#pragma once
#include "./Element.h"

class __declspec(dllexport) XYY_LightElement : public XYY_Element
{
	/*
		��Ԫ�� ��һ������״�� �� �����ʵ�壬 ����Ϊ �����һ�� ����Ԫ��
		�������� ��ֲ�����
	*/
public:
	// std::vector<XYY_LocalDriver *> ld;
	XYY_LocalLightDriver * ld_light;

	XYY_LightElement(int tp = 1);
	void setcolor(glm::vec4 _color_a);
	void setcolor(glm::vec3 _color);

};