#pragma once
#include "PointLight.h"

PointLight::PointLight()
{
	type = 2;//// 1：平行光 2：点光源 3：聚光源

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