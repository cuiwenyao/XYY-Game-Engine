#ifndef CUBE_H
#define CUBE_H

#include "Element.h"
#include "Shader.h"
#include <iostream>
#include <vector>
class Cube : public Element 
{
public:

	struct Texture {
		unsigned int id;
		std::string type;
		std::string path;
	};

	//Shader* shader;
	float vertices[18 * 6];
	unsigned int cubeVAO, cubeVBO;
	std::vector<Texture>cubetextures;
	Cube(const std::string& texturepath = std::string(),unsigned int type=1,glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f), float angle = 0.0f, glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 1.0f));

	void draw();
	void update();
	void move(glm::vec3 translation);//
	void Stretch(glm::vec3 scale);//
	void spin(float angle, glm::vec3 rotation);//
	void setposition(glm::vec3 position);
	void attachtexture(const std::string& texturepath, unsigned int texturetype);
};


#endif

