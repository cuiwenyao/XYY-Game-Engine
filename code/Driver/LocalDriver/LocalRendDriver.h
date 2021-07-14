#pragma once

#include "./LocalDriver.h"

// ---------------声明默认参数 （以下信息为临时信息，后续可以修改，增强代码统一性）
#define XYY_DEFAULT_SPEED 10
#define XYY_DEAFULT_FRONT glm::vec3(0,0,-1)
#define XYY_DEFAULT_POSITION glm::vec3(0,0,0)
#define XYY_DEFAULT_VELOCITY glm::vec3(0,0,0)
#define XYY_DEFAULT_COLOR glm::vec3(1,1,1)
#define XYY_DEFAULT_COLOR_A glm::vec4(1,1,1,1)
// ---------------


class __declspec(dllexport) XYY_LocalRendDriver : public XYY_LocalDriver
{
public:
	int type = 0;			// 0：model  1：cube  2:skybox
	// 基本渲染属性
	glm::vec3 front;		// 朝向，或者光的方向
	
	glm::vec3 velocity;		// 速度 ， 暂时没有用
	glm::vec3 color;		// 纯颜色
	glm::vec4 color_a;		// 带透明度的颜色
	glm::vec3 scale;		// 大小
	
	//  三个matrix
	glm::mat4 modelmat;		
	glm::mat4 viewmat;
	glm::mat4 projectionmat;

	//光照信息 lightdrive根据场景的光照信息进行元素的光照计算与渲染。
	unsigned int shininess = 32;

	// 一些资源属性，不同类型元素的渲染使用不同的资源
	XYY_ShaderResource  * shader;		// 多个 Element 可以使用 同一个Shader
	XYY_ModelResource   * model;		// 多个 Element 可以使用 同一个Model
	XYY_CubeResource	* cube;		
	XYY_SkyboxResource	* skybox;
		
	void run();							// 运行该局部驱动
		
	void move(glm::vec3 translation);			// 移动
	void Stretch(glm::vec3 scale);				// 放缩
	void spin(float angle, glm::vec3 rotation);		// 旋转

	void setposition(glm::vec3 position);		// 设置位置
	glm::vec3 getposition();					// 获取位置

private:
	glm::vec3 position;		// 位置

	void draw();
	void update();

};