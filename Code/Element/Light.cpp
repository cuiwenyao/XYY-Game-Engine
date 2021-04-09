#pragma once 

#include "Light.h"


Light::Light()
{
	speed = XYY_DEFAULT_SPEED;
	front = XYY_DEAFULT_FRONT;
	color = XYY_DEFAULT_COLOR;
	color_a = XYY_DEFAULT_COLOR_A;
	position = XYY_DEFAULT_POSITION;
	velocity = XYY_DEFAULT_VELOCITY;
}
//让光朝向对应的点
void Light::towardsat(glm::vec3 targetposition)
{
	front = targetposition - position;
}
