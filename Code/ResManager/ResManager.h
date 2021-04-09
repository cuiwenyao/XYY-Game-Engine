#pragma once
#ifndef RESMANAGER_H
#define RESMANAGER_H

#define XYY_TEXTURE_TYPE_AMBIENT 1
#define XYY_TEXTURE_TYPE_DIFFUSE 2
#define XYY_TEXTURE_TYPE_SPECULAR 3
#define XYY_TEXTURE_TYPE_NORMAL 4

#include <iostream>
#include <vector>
//资源管理模块
static class ResManager
{
public:
	static unsigned int loadcubemap(std::vector<std::string> faces);
	static unsigned int loadtexture(const std::string& path, bool gamma = false);
	//模型文件中存有相对路径下的材质路径，所以需要directory，来寻址
	static unsigned int loadmodeltexture(const std::string& path, const std::string& directory, bool gamma = false);
	static void seticon(const std::string& iconpath);
};



#endif
