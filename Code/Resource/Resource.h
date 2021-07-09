#pragma once

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <vector>

/*
	Model   用到 Mesh、Shader 
	Mesh    用到 Texture、Vecter（Vectex不在专门建立资源管理类，主要是一种数据结构）等 
*/

class XYY_Resource
{
public:
	std::string path;	//  资源路径  
	
	static unsigned char* xyy_stbi_load(const char *filename, int * x, int * y, int * comp, int req_comp);

	static void xyy_stbi_image_free(void * ret_val_from_stbi_load);
};