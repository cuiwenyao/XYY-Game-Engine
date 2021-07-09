#pragma once

#include "./GlobalDriver.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "./../Driver.h"
#include "../../Scene/SceneContent.h"
#include "../LocalDriver/LocalRendDriver.h"
#include "../LocalDriver/LocalLightDriver.h"
// ... 在这里引入各种局部驱动，使所有的全局驱动都可以方便地调度局部驱动的函数
#include "../../Element/Element.h"
#include "../../Element/ObjectElement.h"
#include "../../Element/CameraElement.h"
#include "../../Element/LightElement.h"
// ... 在这里引入各种元素，使所有的全局驱动都可以方便地调度各种元素
#include "../../Resource/Window.h"
// ... 在这里引入各种资源

class XYY_GlobalLightRendDriver : public XYY_GlobalDriver
{
public:
	int tag = 0 ;						// 该全局驱动对应的标签（用于连接局部驱动与物理驱动）
	int rend_tag = 0, light_tag = 1;	// 渲染局部驱动标签 、 灯光局部驱动标签

	void init();
	void run(XYY_SceneContent * sc);

};