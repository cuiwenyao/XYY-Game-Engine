#pragma once 
#include "DirLight.h"

DirLight::DirLight()
{
	type = 1;//// 1��ƽ�й� 2�����Դ 3���۹�Դ
	speed = XYY_DEFAULT_SPEED;
	front = glm::vec3(-0.2f, -1.0f, -0.3f);
	color = glm::vec3(1, 0, 0);
	color_a = XYY_DEFAULT_COLOR_A;
	position = XYY_DEFAULT_POSITION;
	velocity = XYY_DEFAULT_VELOCITY;
}
void DirLight::update()
{
	;
}