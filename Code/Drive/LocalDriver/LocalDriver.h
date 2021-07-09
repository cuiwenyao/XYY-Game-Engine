#pragma once

#include "./../Driver.h"

/*
写在这里：
	局部驱动用于封装 物体所具有的某种特定功能，如渲染、物理、动画等。
	局部驱动封装 自己所用到的相关属性 及 方法。

一个问题：
	多个局部驱动公用一个Element的某个属性时如何处理呢？
			--- 亟待解决！

*/
/*
局部驱动序号分配（一个全局驱动可能调度多个局部驱动）：
	0：LocalRendDriver
	1：LocalLightDriver
*/

class XYY_LocalDriver : public XYY_Driver
{
public:
	int tag;


};