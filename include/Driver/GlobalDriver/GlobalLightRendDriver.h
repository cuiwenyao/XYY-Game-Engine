#pragma once

#include "./GlobalDriver.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



class   XYY_GlobalLightRendDriver : public XYY_GlobalDriver
{
public:
	int rend_tag = 0, light_tag = 1;	// ��Ⱦ�ֲ�������ǩ �� �ƹ�ֲ�������ǩ

	void init();
	void run(XYY_SceneContent * sc);

};