#pragma once
#include "./SkyboxResource.h"


XYY_SkyboxResource::XYY_SkyboxResource(const std::string& skyboxpath)
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

//	skyboxshader = new Shader("GLSL/skybox.vert", "GLSL/skybox.frag");
	cubemapTexture = loadcubemap(faces);
}

void XYY_SkyboxResource::draw(XYY_ShaderResource * shader)
{
	// draw skybox as last
	glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
	// shader->use();
	shader->setInt("skybox", 0);
	//std::cout << "cubemapTexture:" << cubemapTexture << std::endl;
//	modelmat = glm::mat4(1.0f);
//	viewmat = glm::mat4(glm::mat3(GlobalVariable::camerausing->GetViewMatrix())); // remove translation from the view matrix
//	projectionmat = glm::perspective(glm::radians(GlobalVariable::camerausing->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//	skyboxshader->setMat4("model", modelmat);
//	skyboxshader->setMat4("view", viewmat);
//	skyboxshader->setMat4("projection", projectionmat);
	// skybox cube
	glBindVertexArray(skyboxVAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
	glDepthFunc(GL_LESS); // set depth function back to default
}


unsigned int XYY_SkyboxResource::loadcubemap(std::vector<std::string> faces)
{
//	std::cout << "正在加载天空盒: " << std::endl;
	unsigned int textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

	int width, height, nrChannels;
	for (unsigned int i = 0; i < faces.size(); i++)
	{
	//	std::cout << faces[i] << std::endl;
		unsigned char* data = xyy_stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			//依次填充纹理的每一个面
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			xyy_stbi_image_free(data);
		}
		else
		{
		//	std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
			xyy_stbi_image_free(data);
		}
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	return textureID;
}

