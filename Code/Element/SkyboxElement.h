#pragma once
#include "./ObjectElement.h"

class XYY_SkyboxElement : public XYY_ObjectElement
{
public:
	XYY_LocalRendDriver * ld_rend;

	XYY_SkyboxElement(const std::string& skyboxpath, XYY_ShaderResource * _shader);
	
};

