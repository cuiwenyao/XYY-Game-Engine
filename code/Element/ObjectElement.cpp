#include "./ObjectElement.h"

XYY_ObjectElement::XYY_ObjectElement()
{
	return;
}

XYY_ObjectElement::XYY_ObjectElement(XYY_ModelResource * model, XYY_ShaderResource * shader, unsigned int type, glm::vec3 position, glm::vec3 scale, float angle, glm::vec3 rotation)
{
	this->ld_rend = new XYY_LocalRendDriver();
	this->type = type;				// 设置元素类型
	this->ld_rend->setposition(position);
	this->ld_rend->scale = scale;
	this->ld_rend->model = model;
	this->ld_rend->shader = shader;
	//	GlobalVariable::objectscount++;
	//	this->id = (GlobalVariable::objectscount + GlobalVariable::cubescount + GlobalVariable::planescount);
	this->ld_rend->modelmat = glm::mat4(1.0f);
	this->ld_rend->modelmat = glm::translate(this->ld_rend->modelmat, position);
	this->ld_rend->modelmat = glm::scale(this->ld_rend->modelmat, scale);
	this->ld_rend->modelmat = glm::rotate(this->ld_rend->modelmat, glm::radians(angle), rotation);
//	this->ld_rend->update();
}

XYY_ObjectElement::XYY_ObjectElement(const std::string modelpath, XYY_ShaderResource * shader, unsigned int type, glm::vec3 position, glm::vec3 scale, float angle, glm::vec3 rotation)
{
	this->ld_rend = new XYY_LocalRendDriver();
	this->type = type;				// 设置元素类型
	this->ld_rend->setposition(position);
	this->ld_rend->scale = scale;
	load_model(modelpath);
	this->ld_rend->shader = shader;
//	GlobalVariable::objectscount++;
//	this->id = (GlobalVariable::objectscount + GlobalVariable::cubescount + GlobalVariable::planescount);
	this->ld_rend->modelmat = glm::mat4(1.0f);
	this->ld_rend->modelmat = glm::translate(this->ld_rend->modelmat, position);
	this->ld_rend->modelmat = glm::scale(this->ld_rend->modelmat, scale);
	this->ld_rend->modelmat = glm::rotate(this->ld_rend->modelmat, glm::radians(angle), rotation);
//	this->ld_rend->update();
}

//加载模型
void XYY_ObjectElement::load_model(std::string const& modelpath)
{
	this->ld_rend->model = new XYY_ModelResource(modelpath);
}

