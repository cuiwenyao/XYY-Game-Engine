//#pragma once
#ifndef ELEMENT_H
#define ELEMENT_H

//����Ĭ�ϲ���
#define XYY_DEFAULT_SPEED 10
#define XYY_DEAFULT_FRONT glm::vec3(0,0,-1)
#define XYY_DEFAULT_POSITION glm::vec3(0,0,0)
#define XYY_DEFAULT_VELOCITY glm::vec3(0,0,0)
#define XYY_DEFAULT_COLOR glm::vec3(1,1,1)
#define XYY_DEFAULT_COLOR_A glm::vec4(1,1,1,1)


#include "Shader.h"
#include "Model.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

//GTND everything is element
//Ԫ������Ǹ���׸����ʱ���Ԫ��������ˡ� Ԫ�ط�Ϊ���֣�object �� light��   cameraӦ����component
class Element
{
public:
	unsigned int type;//Ԫ�ص�������  1Ϊ��ͨ���塣��Ⱦ���Ⱥ�˳��    
	unsigned int id;//Ԫ�ص�id Ψһ��ʶһ��Ԫ��
	float speed=10;//�ٶ�

	glm::vec3 front;//���򣬻��߹�ķ���
	glm::vec3 position;//λ��
	glm::vec3 velocity;
	glm::vec3 color;//����ɫ
	glm::vec4 color_a;//��͸���ȵ���ɫ
	glm::vec3 scale;
	glm::mat4 modelmat;
	glm::mat4 viewmat;
	glm::mat4 projectionmat;

	//������Ϣ�� lightdrive���ݳ����Ĺ�����Ϣ����Ԫ�صĹ��ռ�������Ⱦ��
	unsigned int shininess = 32;


	Shader* shader;
	Model* model;

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void move(glm::vec3 translation)=0;//
	virtual void Stretch(glm::vec3 scale)=0;//
	virtual void spin(float angle, glm::vec3 rotation)=0;//
	virtual void setposition(glm::vec3 position) = 0;
};

#endif
