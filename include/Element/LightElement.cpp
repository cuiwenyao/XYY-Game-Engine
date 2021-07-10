#include "./LightElement.h"


XYY_LightElement::XYY_LightElement(int tp)
{
	ld_light = new XYY_LocalLightDriver();
	ld_light->type = tp;

	ld_light->front	   = XYY_DEAFULT_FRONT;
	ld_light->color    = XYY_DEFAULT_COLOR;
	ld_light->color_a  = XYY_DEFAULT_COLOR_A;
	ld_light->position = XYY_DEFAULT_POSITION;
	ld_light->velocity = XYY_DEFAULT_VELOCITY;

	ld_light->ambientlight = XYY_DEFAULT_COLOR;
	ld_light->diffuselight = XYY_DEFAULT_COLOR;
	ld_light->specularlight = XYY_DEFAULT_COLOR;

	ld_light->ambientlight_a = XYY_DEFAULT_COLOR_A;
	ld_light->diffuselight_a = XYY_DEFAULT_COLOR_A;
	ld_light->specularlight_a = XYY_DEFAULT_COLOR_A;

	if (tp == 1)
	{
		ld_light->front = XYY_DEAFULT_FRONT;
		ld_light->color = XYY_DEFAULT_COLOR;
		ld_light->color_a = XYY_DEFAULT_COLOR_A;
		ld_light->position = XYY_DEFAULT_POSITION;
		ld_light->velocity = XYY_DEFAULT_VELOCITY;

		ld_light->constant = 1.0f;
		ld_light->linear = 0.09f;
		ld_light->quadratic = 0.032f;
	}
	else if (tp == 2)
	{
	//	ld_light->front = GlobalVariable::camerausing->Front;
		ld_light->color = XYY_DEFAULT_COLOR;
		ld_light->color_a = XYY_DEFAULT_COLOR_A;
		ld_light->position = XYY_DEFAULT_POSITION;
		ld_light->velocity = XYY_DEFAULT_VELOCITY;

		ld_light->constant = 1.0f;
		ld_light->linear = 0.09f;
		ld_light->quadratic = 0.032f;
		ld_light->cutOff = glm::cos(glm::radians(12.5f));
		ld_light->outerCutOff = glm::cos(glm::radians(15.0f));
	}

}


void XYY_LightElement::setcolor(glm::vec3 _color)
{
	ld_light->color = ld_light->ambientlight = ld_light->diffuselight = ld_light->specularlight  = _color;

}

void XYY_LightElement::setcolor(glm::vec4 _color_a)
{
	ld_light->color_a = ld_light->ambientlight_a = ld_light->diffuselight_a = ld_light->specularlight_a = _color_a;

}