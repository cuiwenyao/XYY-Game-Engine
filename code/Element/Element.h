#pragma once

#include <vector>
#include <map>
#include "../Driver/LocalDriver/LocalDriver.h"
#include "../Driver/LocalDriver/LocalRendDriver.h"
#include "../Driver/LocalDriver/LocalLightDriver.h"


class __declspec(dllexport) XYY_Element
{
public:
	unsigned int type;					// 元素的种类编号		 定义为：  0：灯光  1：普通物体  2：其他（天空盒等）
	std::string id = "0";				// 元素标识器

	
};

