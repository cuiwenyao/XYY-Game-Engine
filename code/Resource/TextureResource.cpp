#pragma once
#include "./TextureResource.h"
#include <glad/glad.h>

#include <iostream>

XYY_TextureResource::XYY_TextureResource()
{
	return;
}

XYY_TextureResource::XYY_TextureResource(const std::string & path, unsigned int texturetype)
{
	this->path = path;
	if (texturetype == XYY_TEXTURE_TYPE_AMBIENT)
	{
		type = "texture_ambient";
	}
	else if (texturetype == XYY_TEXTURE_TYPE_DIFFUSE)
	{
		type = "texture_diffuse";
	}
	else if (texturetype == XYY_TEXTURE_TYPE_SPECULAR)
	{
		type = "texture_specular";
	}
	else if (texturetype == XYY_TEXTURE_TYPE_NORMAL)
	{
		type = "texture_normal";
	}
	loadtexture();
}

unsigned int XYY_TextureResource::loadtexture()
{
//	std::cout << "XYY Game Engine is loading texture: " << path << std::endl;
	unsigned int textureID;
	glGenTextures(1, &textureID);

	//stbi_set_flip_vertically_on_load(true);
	int width, height, nrComponents;
	unsigned char* data = xyy_stbi_load(path.c_str(), &width, &height, &nrComponents, 0);
	if (data)
	{
	//	std::cout << "Texture succeed to load at path: " << path << std::endl;
		GLenum format;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		xyy_stbi_image_free(data);
	}
	else
	{
	//	std::cout << "Texture failed to load at path: " << path << std::endl;
		xyy_stbi_image_free(data);
	}

	return this->id=textureID;

}

unsigned int XYY_TextureResource::loadmodeltexture(const std::string& directory)
{
	std::string filename = std::string(path);
	//std::cout << "filename: " << filename << std::endl;
	if (filename.find('\\') == std::string::npos)
	{
		filename = directory + '/' + filename;//
	}
	else
	{
		filename = filename.substr(filename.find_last_of('\\'), filename.length());
		filename = directory + filename;//
	}
//	std::cout << "XYY Game Engine is loading modeltexture: " << filename << std::endl;

	unsigned int textureID;
	glGenTextures(1, &textureID);

	//stbi_set_flip_vertically_on_load(true);
	int width, height, nrComponents;
	unsigned char* data = xyy_stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
	if (data)
	{
	//	std::cout << "Texture succeed to load at path: " << path << std::endl;
		GLenum format = GL_RGB;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		xyy_stbi_image_free(data);
	}
	else
	{
	//	std::cout << "Texture failed to load at path: " << path << std::endl;
		xyy_stbi_image_free(data);
	}

	return  this->id = textureID;

}