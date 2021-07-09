#include "./LocalLightDriver.h"

XYY_LocalLightDriver::XYY_LocalLightDriver()
{
	speed = XYY_DEFAULT_SPEED;
	front = XYY_DEAFULT_FRONT;
	color = XYY_DEFAULT_COLOR;
	color_a = XYY_DEFAULT_COLOR_A;
	position = XYY_DEFAULT_POSITION;
	velocity = XYY_DEFAULT_VELOCITY;
}

void XYY_LocalLightDriver::run(XYY_LocalRendDriver * lrd,unsigned int &dirlight_count, unsigned int &pointlight_count, unsigned int & spotlight_count)
{
//	std::cout << "灯光" << type << std::endl;
	if (type == 0)
	{
		//平行光
		std::string count = std::to_string(dirlight_count++);
		lrd->shader->setVec3(("dirLight[" + count + "].direction").c_str(), front);
		lrd->shader->setVec3(("dirLight[" + count + "].color").c_str(),  color);
		lrd->shader->setVec3(("dirLight[" + count + "].ambient").c_str(),  ambientlight);
		lrd->shader->setVec3(("dirLight[" + count + "].diffuse").c_str(),  diffuselight);
		lrd->shader->setVec3(("dirLight[" + count + "].specular").c_str(),  specularlight);
	}
	else if (type == 1)
	{
		//点光源
		std::string count = std::to_string(pointlight_count++);
		lrd->shader->setVec3("pointLight[" + count + "].position",  position);
		lrd->shader->setVec3(("pointLight[" + count + "].color").c_str(),  color);
		lrd->shader->setVec3("pointLight[" + count + "].ambient",  ambientlight);
		lrd->shader->setVec3("pointLight[" + count + "].diffuse",  diffuselight);
		lrd->shader->setVec3("pointLight[" + count + "].specular",  specularlight);
		lrd->shader->setFloat("pointLight[" + count + "].constant",  constant);
		lrd->shader->setFloat("pointLight[" + count + "].linear",  linear);
		lrd->shader->setFloat("pointLight[" + count + "].quadratic",  quadratic);
	}
	else if (type == 2)
	{
		//聚光源
		std::string count = std::to_string(spotlight_count++);
		lrd->shader->setVec3(("spotLight[" + count + "].direction").c_str(),  front);
		lrd->shader->setVec3(("spotLight[" + count + "].color").c_str(),  color);
		lrd->shader->setVec3("spotLight[" + count + "].position",  position);
		lrd->shader->setVec3("spotLight[" + count + "].ambient",  ambientlight);
		lrd->shader->setVec3("spotLight[" + count + "].diffuse",  diffuselight);
		lrd->shader->setVec3("spotLight[" + count + "].specular",  specularlight);
		lrd->shader->setFloat("spotLight[" + count + "].constant",  constant);
		lrd->shader->setFloat("spotLight[" + count + "].linear",  linear);
		lrd->shader->setFloat("spotLight[" + count + "].quadratic",  quadratic);
		lrd->shader->setFloat("spotLight[" + count + "].cutOff",  cutOff);
		lrd->shader->setFloat("spotLight[" + count + "].outerCutOff",  outerCutOff);
	}

}


void XYY_LocalLightDriver::towardsat(glm::vec3 targetposition)
{
	front = targetposition - position;
}