#pragma once

#include "./Resource.h"


#define XYY_TEXTURE_TYPE_AMBIENT 1
#define XYY_TEXTURE_TYPE_DIFFUSE 2
#define XYY_TEXTURE_TYPE_SPECULAR 3
#define XYY_TEXTURE_TYPE_NORMAL 4

class XYY_TextureResource : public XYY_Resource
{
public:
	unsigned int id;
	std::string type;
	std::string path;

	XYY_TextureResource();
	XYY_TextureResource(const std::string & path, unsigned int texturetype);
	unsigned int loadtexture();
	unsigned int loadmodeltexture(const std::string& directory);


};