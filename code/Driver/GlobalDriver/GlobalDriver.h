#pragma once

#include "./../Driver.hpp"
#include "../../Scene/SceneContent.h"
#include "../LocalDriver/LocalRendDriver.h"
#include "../LocalDriver/LocalLightDriver.h"
// ... 在这里引入各种局部驱动，使所有的全局驱动都可以方便地调度局部驱动的函数
#include "../../Element/Element.h"
#include "../../Element/ObjectElement.h"
#include "../../Element/CameraElement.h"
#include "../../Element/LightElement.h"
// ... 在这里引入各种元素，使所有的全局驱动都可以方便地调度各种元素

// ... 在这里引入各种资源


/*
写在这里：
	全局驱动负责实现场景的某个整体功能，如渲染、物理、动画等。
	其主要完成两类工作：1、统筹场景内容中各个Element局部驱动（与该全局驱动一致的）的运行顺序 2、调度运行各个局部驱动

一个问题：
	一个全局驱动 如何 “快速” 在一个Element的多个局部驱动中“找到” 与自己匹配（实现统一功能）的那个局部驱动？
		解决方案：1（采纳）、在匹配的全局驱动 和 局部驱动之间定义标识符 2、使用 对象类型识别函数
*/

class __declspec(dllexport) XYY_GlobalDriver : public XYY_Driver
{
	public:
		void init();						// 初始化
		void run(XYY_SceneContent * sc);	// 运行


};