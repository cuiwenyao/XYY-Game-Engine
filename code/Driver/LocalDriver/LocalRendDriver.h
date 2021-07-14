#pragma once

#include "./LocalDriver.h"

// ---------------����Ĭ�ϲ��� ��������ϢΪ��ʱ��Ϣ�����������޸ģ���ǿ����ͳһ�ԣ�
#define XYY_DEFAULT_SPEED 10
#define XYY_DEAFULT_FRONT glm::vec3(0,0,-1)
#define XYY_DEFAULT_POSITION glm::vec3(0,0,0)
#define XYY_DEFAULT_VELOCITY glm::vec3(0,0,0)
#define XYY_DEFAULT_COLOR glm::vec3(1,1,1)
#define XYY_DEFAULT_COLOR_A glm::vec4(1,1,1,1)
// ---------------


class __declspec(dllexport) XYY_LocalRendDriver : public XYY_LocalDriver
{
public:
	int type = 0;			// 0��model  1��cube  2:skybox
	// ������Ⱦ����
	glm::vec3 front;		// ���򣬻��߹�ķ���
	
	glm::vec3 velocity;		// �ٶ� �� ��ʱû����
	glm::vec3 color;		// ����ɫ
	glm::vec4 color_a;		// ��͸���ȵ���ɫ
	glm::vec3 scale;		// ��С
	
	//  ����matrix
	glm::mat4 modelmat;		
	glm::mat4 viewmat;
	glm::mat4 projectionmat;

	//������Ϣ lightdrive���ݳ����Ĺ�����Ϣ����Ԫ�صĹ��ռ�������Ⱦ��
	unsigned int shininess = 32;

	// һЩ��Դ���ԣ���ͬ����Ԫ�ص���Ⱦʹ�ò�ͬ����Դ
	XYY_ShaderResource  * shader;		// ��� Element ����ʹ�� ͬһ��Shader
	XYY_ModelResource   * model;		// ��� Element ����ʹ�� ͬһ��Model
	XYY_CubeResource	* cube;		
	XYY_SkyboxResource	* skybox;
		
	void run();							// ���иþֲ�����
		
	void move(glm::vec3 translation);			// �ƶ�
	void Stretch(glm::vec3 scale);				// ����
	void spin(float angle, glm::vec3 rotation);		// ��ת

	void setposition(glm::vec3 position);		// ����λ��
	glm::vec3 getposition();					// ��ȡλ��

private:
	glm::vec3 position;		// λ��

	void draw();
	void update();

};