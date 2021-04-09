#pragma once
#include "Object.h"

#include "../Component/Window.h"
#include "../Variable/GlobalVariable.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
Object::Object(const std::string modelpath, unsigned int type, glm::vec3 position, glm::vec3 scale,float angle,glm::vec3 rotation)
{
	std::cout << "���ڼ���ģ��" << modelpath <<std::endl;
	this->type = type;//����Ԫ������
	this->position = position;
	this->scale = scale;
	load_model(modelpath);
	this->shader = GlobalVariable::defaultobjectshader;
	GlobalVariable::objectscount++;
	this->id = (GlobalVariable::objectscount + GlobalVariable::cubescount + GlobalVariable::planescount);
	modelmat = glm::mat4(1.0f);
	modelmat = glm::translate(modelmat, position);
	modelmat = glm::scale(modelmat, scale);
	modelmat = glm::rotate(modelmat, glm::radians(angle), rotation);
	update();
}

//����ģ��
void Object::load_model(std::string const& modelpath)
{
	this->model = new Model(modelpath);
}
void Object::draw()
{
	model->Draw(*shader);
}
void Object::update()
{
	//std::cout << "object update" << std::endl;
	shader->use();
	shader->setMat4("model", modelmat);
	shader->setMat4("view", viewmat);
	shader->setMat4("projection", projectionmat);
}
void Object::move(glm::vec3 translation)
{
	position += translation;
	modelmat = glm::translate(modelmat, translation);
	update();
}
void Object::Stretch(glm::vec3 scale)
{
	this->scale *= scale;
	modelmat = glm::scale(modelmat, scale);
	update();
}
void Object::spin(float angle, glm::vec3 rotation)
{
	//��ʱ������Ԫ�����պ���ʱ�佫���е������Ϊ��Ԫ����ʾ������ʹ��ŷ���ǻ���BUG;
	modelmat = glm::rotate(modelmat, glm::radians(angle), rotation);
	update();
}
void Object::setposition(glm::vec3 position)
{
	move(position - this->position);
}


