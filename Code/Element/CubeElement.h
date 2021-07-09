#pragma once
#include "./ObjectElement.h"

class XYY_CubeElement : public XYY_ObjectElement
{
public:
	// XYY_LocalRendDriver * ld_rend;

	// XYY_ShaderResource * shader;
	
	float vertices[18 * 6];
	unsigned int cubeVAO, cubeVBO;
	std::vector<XYY_TextureResource> cubetextures;
	XYY_CubeElement(XYY_ShaderResource * shader, unsigned int type = 1, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f), float angle = 0.0f, glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 1.0f));

	void addtexture(XYY_TextureResource * texture);

	void addtexture(const std::string& texturepath, unsigned int texturetype);

};
