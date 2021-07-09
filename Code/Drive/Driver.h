#pragma once

#include <vector>
#include "../Resource/Resource.h"
#include "../Resource/ShaderResource.h"
#include "../Resource/TextureResource.h"
#include "../Resource/ModelResource.h"
#include "../Resource/MeshResource.h"
#include "../Resource/CubeResource.h"
#include "../Resource/SkyboxResource.h"
// ... ���������������Դ�� ���Ϳ�����Scene �� ��������ֱ��ʹ��

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class XYY_Driver
{
public:
	int tag;							 // ��ǩ����������ȫ����������������
	std::vector<XYY_Resource> resources; // ��Դ�� �� �����Ļ��������ǵ�����Դ

	void run();
};