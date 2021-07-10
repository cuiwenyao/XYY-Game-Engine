#include "./CubeResource.h"



XYY_CubeResource::XYY_CubeResource(const std::string& texturepath, unsigned int type, glm::vec3 position, glm::vec3 scale, float angle, glm::vec3 rotation)
{
	float vertices[] = {
		// positions          // normals           // texture coords
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
	};


	// shader = new XYY_ShaderResource("GLSL/object.vert", "GLSL/object.frag");

	//this->type = type;		//设置元素类型
	//this->position = position;
	//this->scale = scale;

	//modelmat = glm::mat4(1.0f);
	//modelmat = glm::translate(modelmat, position);
	//modelmat = glm::scale(modelmat, scale);
	//modelmat = glm::rotate(modelmat, glm::radians(angle), rotation);

	glGenVertexArrays(1, &cubeVAO);
	glGenBuffers(1, &cubeVBO);
	glBindVertexArray(cubeVAO);
	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	// GlobalVariable::cubescount++;
	// this->id = (GlobalVariable::objectscount + GlobalVariable::cubescount + GlobalVariable::planescount);

}

void XYY_CubeResource::draw(XYY_ShaderResource * shader)
{
	// shader->use();

	// bind appropriate textures
	unsigned int diffuseNr = 0;
	unsigned int specularNr = 0;
	unsigned int normalNr = 0;
	unsigned int heightNr = 0;
	unsigned int ambientNr = 0;
	unsigned int basecolorNr = 0;
	unsigned int ambientocclusionNr = 0;
	unsigned int diffuseroughnessNr = 0;
	for (unsigned int i = 0; i < cubetextures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i); // active proper texture unit before binding
		// retrieve texture number (the N in diffuse_textureN)
		std::string number;
		std::string name = cubetextures[i]->type;
		if (name == "texture_diffuse")
			number = std::to_string(diffuseNr++);
		else if (name == "texture_specular")
			number = std::to_string(specularNr++);			// transfer unsigned int to stream
		else if (name == "texture_normal")
			number = std::to_string(normalNr++);			// transfer unsigned int to stream
		else if (name == "texture_height")
			number = std::to_string(heightNr++);			// transfer unsigned int to stream
		else if (name == "texture_ambient")
			number = std::to_string(ambientNr++);			// transfer unsigned int to stream
		else if (name == "texture_basecolor")
			number = std::to_string(basecolorNr++);			// transfer unsigned int to stream
		else if (name == "texture_ambientocclusion")
			number = std::to_string(ambientocclusionNr++);	// transfer unsigned int to stream
		else if (name == "texture_diffuseroughness")
			number = std::to_string(diffuseroughnessNr++);	// transfer unsigned int to stream


		glUniform1i(glGetUniformLocation(shader->ID, (name + "[" + number + "]").c_str()), i);//第i个纹理单元

		glBindTexture(GL_TEXTURE_2D, cubetextures[i]->id);
	}

	glUniform1i(glGetUniformLocation(shader->ID, "texture_ambient_count"), ambientNr);
	glUniform1i(glGetUniformLocation(shader->ID, "texture_diffuse_count"), diffuseNr);
	glUniform1i(glGetUniformLocation(shader->ID, "texture_specular_count"), specularNr);
	glUniform1i(glGetUniformLocation(shader->ID, "texture_normal_count"), normalNr);


	// projectionmat = glm::perspective(glm::radians(GlobalVariable::camerausing->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
	// viewmat = GlobalVariable::camerausing->GetViewMatrix();

	// shader->setMat4("model", modelmat);
	// shader->setMat4("view", viewmat);
	// shader->setMat4("projection", projectionmat);


	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, cubetextures);

	glBindVertexArray(cubeVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}

void XYY_CubeResource::attachtexture(XYY_TextureResource * texture)
{
	cubetextures.push_back(texture);
}

void XYY_CubeResource::attachtexture(const std::string& texturepath, unsigned int texturetype)
{
	if (!texturepath.empty())
	{
		XYY_TextureResource * texture = new XYY_TextureResource(texturepath, texturetype);
		cubetextures.push_back(texture);
	}

}