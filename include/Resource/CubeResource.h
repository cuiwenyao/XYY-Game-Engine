#pragma once
#include "./Resource.h"
#include "./TextureResource.h"
#include "./ShaderResource.h"


class   XYY_CubeResource : XYY_Resource
{
public:
	float vertices[18 * 6];
	unsigned int cubeVAO, cubeVBO;
	std::vector<XYY_TextureResource *> cubetextures;
	XYY_CubeResource(const std::string& texturepath = std::string(), unsigned int type = 1, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f), float angle = 0.0f, glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 1.0f));

	
	void draw(XYY_ShaderResource * shader);

	void attachtexture(XYY_TextureResource * texture);
	void attachtexture(const std::string& texturepath, unsigned int texturetype);

};