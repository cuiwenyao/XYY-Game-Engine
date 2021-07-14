#pragma once
#include "./Element.h"

class __declspec(dllexport) XYY_ObjectElement : public XYY_Element
{
	/*
		ObjectԪ������Ϸ�д��ڵ�ʵ�壬ӵ�оֲ���Ⱦ���������ֲ���������Ӱ�졣
	*/
public:
	XYY_LocalRendDriver * ld_rend;

	XYY_ObjectElement();
	XYY_ObjectElement(XYY_ModelResource * model, XYY_ShaderResource * shader, unsigned int type = 1, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f), float angle = 0.0f, glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 1.0f));
	XYY_ObjectElement(const std::string modelpath,XYY_ShaderResource * shader, unsigned int type = 1, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f), float angle = 0.0f, glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 1.0f));

private:
	void load_model(std::string const& modelpath);

};