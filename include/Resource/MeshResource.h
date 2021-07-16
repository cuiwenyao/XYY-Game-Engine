#pragma once

#include "./Resource.h"
#include "./ShaderResource.h"
#include "./TextureResource.h"

#include <string>
#include <vector>
#include <iostream>

/* 一些结构性信息 */
struct Vertex {
	// position
	glm::vec3 Position;
	// normal
	glm::vec3 Normal;
	// texCoords
	glm::vec2 TexCoords;
	// tangent
	glm::vec3 Tangent;
	// bitangent
	glm::vec3 Bitangent;
};


class __declspec(dllexport) XYY_MeshResource : public XYY_Resource
{
public:
	// mesh Data
	std::vector<Vertex>       vertices;
	std::vector<unsigned int> indices;
	std::vector<XYY_TextureResource>      textures;
	unsigned int VAO;

	// constructor
	XYY_MeshResource(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<XYY_TextureResource> textures);

	// render the mesh
	void draw(XYY_ShaderResource & shader);

private:
	// render data 
	unsigned int VBO, EBO;

	// initializes all the buffer objects/arrays
	void setupMesh();
};