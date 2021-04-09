#pragma once

#include "SpotLight.h"
#include "../Variable/GlobalVariable.h"


SpotLight::SpotLight()
{
	type = 3;//// 1：平行光 2：点光源 3：聚光源
	speed = XYY_DEFAULT_SPEED;

	front = GlobalVariable::camerausing->Front;
	color = glm::vec3(1, 0, 0);
	color_a = XYY_DEFAULT_COLOR_A;
	position = XYY_DEFAULT_POSITION;
	velocity = XYY_DEFAULT_VELOCITY;

	constant = 1.0f;
	linear = 0.09f;
	quadratic = 0.032f;
	cutOff = glm::cos(glm::radians(12.5f));
	outerCutOff = glm::cos(glm::radians(15.0f));
}

void SpotLight::update()
{
	front = GlobalVariable::camerausing->Front;
	position = GlobalVariable::camerausing->position;
}