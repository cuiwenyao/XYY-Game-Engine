#pragma once
#include "./LocalDriver.h"
#include "./LocalRendDriver.h"	// 发光驱动需要调用渲染驱动

/*
发光局部驱动
*/

// ---------------声明默认参数 （以下信息为临时信息，后续可以修改，增强代码统一性）
#define XYY_DEFAULT_SPEED 10
#define XYY_DEAFULT_FRONT glm::vec3(0,0,-1)
#define XYY_DEFAULT_POSITION glm::vec3(0,0,0)
#define XYY_DEFAULT_VELOCITY glm::vec3(0,0,0)
#define XYY_DEFAULT_COLOR glm::vec3(1,1,1)
#define XYY_DEFAULT_COLOR_A glm::vec4(1,1,1,1)
// ---------------

class   XYY_LocalLightDriver : public XYY_LocalDriver
{
public:
	unsigned int type = 0;		// 0：平行光 1：点光源 2：聚光源
	bool lighton = true;		// 是否打开这个灯

	glm::vec3 front;			// 朝向，或者光的方向
	glm::vec3 position;			// 位置
	glm::vec3 velocity;
	glm::vec3 color = glm::vec3(1.0, 1.0, 1.0);			// 纯颜色
	glm::vec4 color_a = glm::vec4(1.0, 1.0, 1.0, 1.0);	// 带透明度的颜色

	float constant;
	float linear;
	float quadratic;
	
	float cutOff;
	float outerCutOff;

	glm::vec3 ambientlight = XYY_DEFAULT_COLOR;
	glm::vec3 diffuselight = XYY_DEFAULT_COLOR;
	glm::vec3 specularlight = XYY_DEFAULT_COLOR;

	glm::vec4 ambientlight_a = XYY_DEFAULT_COLOR_A;
	glm::vec4 diffuselight_a = XYY_DEFAULT_COLOR_A;
	glm::vec4 specularlight_a = XYY_DEFAULT_COLOR_A;

	XYY_LocalLightDriver();
	void run(XYY_LocalRendDriver * lrd, unsigned int &dirlight_count, unsigned int &pointlight_count, unsigned int & spotlight_count);	// 将灯光的效果加到ele上 ，局部驱动是不能直接操作element的， 这样就出现了循环引用，可以接受该element的局部渲染驱动
	void run();		

	//让光朝向对应的点
	void towardsat(glm::vec3 targetposition);
};