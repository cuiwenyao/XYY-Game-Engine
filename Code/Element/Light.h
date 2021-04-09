#ifndef LIGHT_H
#define LIGHT_H

#include "Element.h"

//光照只提供光照信息，可以实时的提供位置，朝向，颜色就可以啦。光照是信息，不需要渲染，不需要shader.
class Light
{
public:

	float speed = 10;//速度
	unsigned int type = 0;//// 1：平行光 2：点光源 3：聚光源
	bool lighton = true;//是否打开这个灯

	glm::vec3 front;//朝向，或者光的方向
	glm::vec3 position;//位置
	glm::vec3 velocity;
	glm::vec3 color = glm::vec3(1.0, 1.0, 1.0);//纯颜色
	glm::vec4 color_a = glm::vec4(1.0, 1.0, 1.0, 1.0);//带透明度的颜色

	float constant;
	float linear;
	float quadratic;
	float cutOff;
	float outerCutOff;

	glm::vec3 ambientlight = glm::vec3(1.0, 1.0, 1.0);
	glm::vec3 diffuselight = glm::vec3(1.0, 1.0, 1.0);
	glm::vec3 specularlight = glm::vec3(1.0, 1.0, 1.0);

	glm::vec4 ambientlight_a = glm::vec4(1.0, 1.0, 1.0, 1.0);
	glm::vec4 diffuselight_a = glm::vec4(1.0, 1.0, 1.0, 1.0);
	glm::vec4 specularlight_a = glm::vec4(1.0, 1.0, 1.0, 1.0);


	Light();

	//让光朝向对应的点
	void towardsat(glm::vec3 targetposition);

	virtual void update() = 0;
};


#endif