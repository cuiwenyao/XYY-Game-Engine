#pragma once

#include <vector>
#include "../Driver/LocalDriver/LocalDriver.h"
#include "../Driver/LocalDriver/LocalRendDriver.h"
#include "../Driver/LocalDriver/LocalLightDriver.h"



class   XYY_Element
{
public:
	unsigned int type;					// 元素的种类编号		 定义为：  0：灯光  1：普通物体  2：其他（天空盒等）
	// std::vector<XYY_LocalDriver *> ld;	// 该元素所拥有的局部驱动 定义为： 0：渲染 1：物理 2：动画
	


//	unsigned int id;					// 元素的id 唯一标识一个元素
	
	
	
	
};

