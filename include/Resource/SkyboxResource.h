#pragma once

#include "./Resource.h"
#include "./ShaderResource.h"


class   XYY_SkyboxResource : XYY_Resource
{
public:
	float skyboxVertices[18 * 6];
	unsigned int skyboxVAO, skyboxVBO;
	std::vector<std::string> faces;
	unsigned int cubemapTexture;

	XYY_SkyboxResource(const std::string& skyboxpath);
	void draw(XYY_ShaderResource * shader);

private:
	unsigned int loadcubemap(std::vector<std::string> faces);
};

