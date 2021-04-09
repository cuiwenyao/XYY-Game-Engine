//#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include "Model.h"
#include "Camera.h"
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <thread>
class Object :public Element 
{
public:

	Object(const std::string modelpath, unsigned int type = 1, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f), float angle = 0.0f, glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 1.0f));
	//Object(Camera* camera, Shader* shader, const std::string modelpath);
	//º”‘ÿƒ£–Õ
	void load_model(std::string const& modelpath);

	//update
	void draw();
	void update();
	void move(glm::vec3 translation);//
	void Stretch(glm::vec3 scale);//
	void spin(float angle, glm::vec3 rotation);//
	void setposition(glm::vec3 position);
};


#endif // !OBJECT_H

