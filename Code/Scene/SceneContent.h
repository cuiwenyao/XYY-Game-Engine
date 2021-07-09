#pragma once

#include "../Element/Element.h"
#include "../Element/LightElement.h"
#include "../Element/ObjectElement.h"
#include "../Element/CameraElement.h"
#include "../Element/CubeElement.h"
#include "../Element/SkyboxElement.h"
// ... ����Ԫ�����������룬��ȫ�������оͿ��뱻ֱ�ӵ���

#include "../tinyxml/tinyxml.h"

#include <vector>
#include <string>
#include <map>

/*
д�����
	���������е�һ��Ԫ�أ�����ָ�����ʽ�洢��������ʵ���� ���� ��̬���䡣 �����Կ���ʵ��һ��ר������������Դ��ģ�飩
*/
class XYY_SceneContent
{
public:
	// Ϊ������ ȫ������ �ĵ����ٶ� �� �� �ƹ⡢��ͨ�������������� �ֿ�����
	std::vector<XYY_LightElement *> Lights;			// �ƹ�
	std::vector<XYY_ObjectElement *> Objects;		// ��ͨ����
	std::vector<XYY_CameraElement *> Cameras;		// ����� ���涨���Ϊ0�������Ϊ��ǰ�������ݵ��������
//	std::vector<XYY_CubeElement *> Cubes;			// ����������
	XYY_SkyboxElement * skybox;						// ��պ�

	// ����Ϊ ��ʱ ���� �� ָ ����ͨ���������º�����ʱ�Ե��޸ĳ������� �� ��׼������Ӧ�����޸��� ���� �ļ��ķ�ʽ
	// ������׼�������� ͨ������ ���� ʵ��
	XYY_SceneContent();
//	void addElement(XYY_Element * ele);

	bool loadXML(const char * path);
	bool saveXML(const char * path);


};