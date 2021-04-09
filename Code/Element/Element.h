//#pragma once
#ifndef ELEMENT_H
#define ELEMENT_H

//声明默认参数
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
//元素类就是个累赘，有时间吧元素类给灭了。 元素分为两种，object 与 light。   camera应该是component
class Element
{
public:
	unsigned int type;//元素的种类编号  1为普通物体。渲染无先后顺序    
	unsigned int id;//元素的id 唯一标识一个元素
	float speed=10;//速度

	glm::vec3 front;//朝向，或者光的方向
	glm::vec3 position;//位置
	glm::vec3 velocity;
	glm::vec3 color;//纯颜色
	glm::vec4 color_a;//带透明度的颜色
	glm::vec3 scale;
	glm::mat4 modelmat;
	glm::mat4 viewmat;
	glm::mat4 projectionmat;

	//光照信息。 lightdrive根据场景的光照信息进行元素的光照计算与渲染。
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
