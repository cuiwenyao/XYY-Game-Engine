#pragma once
#include "PointLight.h"

PointLight::PointLight()
{
	type = 2;//// 1��ƽ�й� 2�����Դ 3���۹�Դ

	speed = XYY_DEFAULT_SPEED;
	front = XYY_DEAFULT_FRONT;
	color = glm::vec3(1,0,0);
	color_a = XYY_DEFAULT_COLOR_A;
	position = XYY_DEFAULT_POSITION;
	velocity = XYY_DEFAULT_VELOCITY;

	constant = 1.0f;
	linear = 0.09f;
	quadratic = 0.032f;
}

void PointLight::update()
{
	;
}