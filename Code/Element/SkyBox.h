#ifndef SKYBOX_H
#define SKYBOX_H

#include "Shader.h"
#include "Element.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>
class SkyBox :public Element
{
public:
    Shader* skyboxshader;
    float skyboxVertices[18 * 6];
    unsigned int skyboxVAO, skyboxVBO;
    std::vector<std::string> faces;
    unsigned int cubemapTexture;

    SkyBox(const std::string& skyboxpath);
    void draw();
    void update();
    void move(glm::vec3 translation);//
    void Stretch(glm::vec3 scale);//
    void spin(float angle, glm::vec3 rotation);//
    void setposition(glm::vec3 position);
};






#endif // !SKYBOX_H
