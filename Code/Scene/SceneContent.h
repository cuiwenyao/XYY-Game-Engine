#pragma once

#include "../Element/Element.h"
#include "../Element/LightElement.h"
#include "../Element/ObjectElement.h"
#include "../Element/CameraElement.h"
#include "../Element/CubeElement.h"
#include "../Element/SkyboxElement.h"
// ... 各种元素在这里引入，在全局驱动中就可与被直接调用

#include "../tinyxml/tinyxml.h"

#include <vector>
#include <string>
#include <map>

/*
写在这里：
	场景内容中的一切元素，都以指针的形式存储，真正的实体由 引擎 动态分配。 （可以考虑实现一个专门用来管理资源的模块）
*/
class XYY_SceneContent
{
public:
	// 为了提升 全局驱动 的调用速度 ， 将 灯光、普通物体与其他物体 分开放置
	std::vector<XYY_LightElement *> Lights;			// 灯光
	std::vector<XYY_ObjectElement *> Objects;		// 普通物体
	std::vector<XYY_CameraElement *> Cameras;		// 摄像机 ，规定序号为0的摄像机为当前场景内容的主摄像机
//	std::vector<XYY_CubeElement *> Cubes;			// 内置立方体
	XYY_SkyboxElement * skybox;						// 天空盒

	// 下面为 临时 函数 ， 指 可以通过调用以下函数临时性的修改场景内容 ， 标准的做法应该是修改与 解析 文件的方式
	// 后续标准做法可以 通过以下 函数 实现
	XYY_SceneContent();
//	void addElement(XYY_Element * ele);

	bool loadXML(const char * path);
	bool saveXML(const char * path);


};