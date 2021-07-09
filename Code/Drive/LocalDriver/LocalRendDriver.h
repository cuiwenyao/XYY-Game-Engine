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


class XYY_LocalRendDriver : public XYY_LocalDriver
{
	public:
		int tag = 0;			// 该驱动对应的标签（用于连接局部驱动与物理驱动） （已经废用）
		int type = 0;			// 0：model  1：cube  2:skybox
		// 基本渲染属性
		glm::vec3 front;		// 朝向，或者光的方向
		glm::vec3 position;		// 位置
		glm::vec3 velocity;
		glm::vec3 color;		// 纯颜色
		glm::vec4 color_a;		// 带透明度的颜色
		glm::vec3 scale;		// 大小

		//  三个matrix
		glm::mat4 modelmat;		
		glm::mat4 viewmat;
		glm::mat4 projectionmat;

		//光照信息 lightdrive根据场景的光照信息进行元素的光照计算与渲染。
		unsigned int shininess = 32;

		// 一些资源属性，下面的属性可以改为更通用的资源调用，不过因为这里已经 专于一种特定的局部渲染驱动，所以我暂时这么写之。
		XYY_ShaderResource  * shader;		// 多个 Element 可以使用 同一个Shader
		XYY_ModelResource   * model;		// 多个 Element 可以使用 同一个Model
		XYY_CubeResource	* cube;		
		XYY_SkyboxResource	* skybox;
		
		void run();							// 运行该局部驱动
		void draw();
		void update();
		void move(glm::vec3 translation);
		void Stretch(glm::vec3 scale);
		void spin(float angle, glm::vec3 rotation);
		void setposition(glm::vec3 position);
};