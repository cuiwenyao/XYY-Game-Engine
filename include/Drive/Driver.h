#pragma once

#include <vector>
#include "../Resource/Resource.h"
#include "../Resource/ShaderResource.h"
#include "../Resource/TextureResource.h"
#include "../Resource/ModelResource.h"
#include "../Resource/MeshResource.h"
#include "../Resource/CubeResource.h"
#include "../Resource/SkyboxResource.h"
#include "../Resource/Window.h"

// ... 在这里引入各种资源类 ，就可以在Scene 与 场景类中直接使用

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class __declspec(dllexport) XYY_Driver
{
public:
	int tag;							 // 标签，用于连接全局驱动与物理驱动
	std::vector<XYY_Resource> resources; // 资源集 ， 驱动的基本特征是调度资源

	void run();
};