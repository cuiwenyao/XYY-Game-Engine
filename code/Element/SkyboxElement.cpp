#include "./SkyboxElement.h"


XYY_SkyboxElement::XYY_SkyboxElement(const std::string& skyboxpath,XYY_ShaderResource * _shader)
{
	ld_rend = new XYY_LocalRendDriver();
	ld_rend->type = 2;
	ld_rend->shader = _shader;
	ld_rend->skybox = new XYY_SkyboxResource(skyboxpath);

}
