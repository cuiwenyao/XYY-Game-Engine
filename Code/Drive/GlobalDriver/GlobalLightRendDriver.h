#pragma once

#include "./GlobalDriver.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "./../Driver.h"
#include "../../Scene/SceneContent.h"
#include "../LocalDriver/LocalRendDriver.h"
#include "../LocalDriver/LocalLightDriver.h"
// ... ������������־ֲ�������ʹ���е�ȫ�����������Է���ص��Ⱦֲ������ĺ���
#include "../../Element/Element.h"
#include "../../Element/ObjectElement.h"
#include "../../Element/CameraElement.h"
#include "../../Element/LightElement.h"
// ... �������������Ԫ�أ�ʹ���е�ȫ�����������Է���ص��ȸ���Ԫ��
#include "../../Resource/Window.h"
// ... ���������������Դ

class XYY_GlobalLightRendDriver : public XYY_GlobalDriver
{
public:
	int tag = 0 ;						// ��ȫ��������Ӧ�ı�ǩ���������Ӿֲ�����������������
	int rend_tag = 0, light_tag = 1;	// ��Ⱦ�ֲ�������ǩ �� �ƹ�ֲ�������ǩ

	void init();
	void run(XYY_SceneContent * sc);

};