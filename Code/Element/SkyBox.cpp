#pragma once
#include "SkyBox.h"
#include <glad/glad.h>
#include "../Variable/GlobalVariable.h"
#include "../ResManager/ResManager.h"

SkyBox::SkyBox(const std::string& skyboxpath)
{
	float skyboxVertices[] = {
		// positions          
		 -1.0f,  1.0f, -1.0f,
		 -1.0f, -1.0f, -1.0f,
		  1.0f, -1.0f, -1.0f,
		  1.0f, -1.0f, -1.0f,
		  1.0f,  1.0f, -1.0f,
		 -1.0f,  1.0f, -1.0f,

		 -1.0f, -1.0f,  1.0f,
		 -1.0f, -1.0f, -1.0f,
		 -1.0f,  1.0f, -1.0f,
		 -1.0f,  1.0f, -1.0f,
		 -1.0f,  1.0f,  1.0f,
		 -1.0f, -1.0f,  1.0f,

		  1.0f, -1.0f, -1.0f,
		  1.0f, -1.0f,  1.0f,
		  1.0f,  1.0f,  1.0f,
		  1.0f,  1.0f,  1.0f,
		  1.0f,  1.0f, -1.0f,
		  1.0f, -1.0f, -1.0f,

		 -1.0f, -1.0f,  1.0f,
		 -1.0f,  1.0f,  1.0f,
		  1.0f,  1.0f,  1.0f,
		  1.0f,  1.0f,  1.0f,
		  1.0f, -1.0f,  1.0f,
		 -1.0f, -1.0f,  1.0f,

		 -1.0f,  1.0f, -1.0f,
		  1.0f,  1.0f, -1.0f,
		  1.0f,  1.0f,  1.0f,
		  1.0f,  1.0f,  1.0f,
		 -1.0f,  1.0f,  1.0f,
		 -1.0f,  1.0f, -1.0f,

		 -1.0f, -1.0f, -1.0f,
		 -1.0f, -1.0f,  1.0f,
		  1.0f, -1.0f, -1.0f,
		  1.0f, -1.0f, -1.0f,
		 -1.0f, -1.0f,  1.0f,
		  1.0f, -1.0f,  1.0f
	};

	/*
		std::vector<std::string> faces =
	{
		"resources/textures/skybox/right.jpg",
		"resources/textures/skybox/left.jpg",
		"resources/textures/skybox/top.jpg",
		"resources/textures/skybox/bottom.jpg",
		"resources/textures/skybox/front.jpg",
		"resources/textures/skybox/back.jpg"
	};
	*/

	std::vector<std::string> faces =
	{
		(skyboxpath + "/right.jpg").c_str(),
		(skyboxpath + "/left.jpg").c_str(),
		(skyboxpath + "/top.jpg").c_str(),
		(skyboxpath + "/bottom.jpg").c_str(),
		(skyboxpath + "/front.jpg").c_str(),
		(skyboxpath + "/back.jpg").c_str()

	};

	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	skyboxshader = new Shader("GLSL/skybox.vert", "GLSL/skybox.frag");
	cubemapTexture = ResManager::loadcubemap(faces);

}

void SkyBox::draw()
{
	// draw skybox as last
	glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
	skyboxshader->use();
	skyboxshader->setInt("skybox", 0);
	//std::cout << "cubemapTexture:" << cubemapTexture << std::endl;
	modelmat = glm::mat4(1.0f);
	viewmat = glm::mat4(glm::mat3(GlobalVariable::camerausing->GetViewMatrix())); // remove translation from the view matrix
	projectionmat = glm::perspective(glm::radians(GlobalVariable::camerausing->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
	skyboxshader->setMat4("model", modelmat);
	skyboxshader->setMat4("view", viewmat);
	skyboxshader->setMat4("projection", projectionmat);
	// skybox cube
	glBindVertexArray(skyboxVAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
	glDepthFunc(GL_LESS); // set depth function back to default
}
void SkyBox::update()
{
	;
}
void SkyBox::move(glm::vec3 translation)
{
	;
}
void SkyBox::Stretch(glm::vec3 scale)
{
	;
}
void SkyBox::spin(float angle, glm::vec3 rotation)
{
	;
}
void SkyBox::setposition(glm::vec3 position)
{
	;
}