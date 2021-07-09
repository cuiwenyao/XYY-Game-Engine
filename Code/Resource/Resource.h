#pragma once

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <vector>

/*
	Model   �õ� Mesh��Shader 
	Mesh    �õ� Texture��Vecter��Vectex����ר�Ž�����Դ�����࣬��Ҫ��һ�����ݽṹ���� 
*/

class XYY_Resource
{
public:
	std::string path;	//  ��Դ·��  
	
	static unsigned char* xyy_stbi_load(const char *filename, int * x, int * y, int * comp, int req_comp);

	static void xyy_stbi_image_free(void * ret_val_from_stbi_load);
};