#pragma once
#include "./LocalDriver.h"
#include "./LocalRendDriver.h"	// ����������Ҫ������Ⱦ����

/*
����ֲ�����
*/

// ---------------����Ĭ�ϲ��� ��������ϢΪ��ʱ��Ϣ�����������޸ģ���ǿ����ͳһ�ԣ�
#define XYY_DEFAULT_SPEED 10
#define XYY_DEAFULT_FRONT glm::vec3(0,0,-1)
#define XYY_DEFAULT_POSITION glm::vec3(0,0,0)
#define XYY_DEFAULT_VELOCITY glm::vec3(0,0,0)
#define XYY_DEFAULT_COLOR glm::vec3(1,1,1)
#define XYY_DEFAULT_COLOR_A glm::vec4(1,1,1,1)
// ---------------

class   XYY_LocalLightDriver : public XYY_LocalDriver
{
public:
	unsigned int type = 0;		// 0��ƽ�й� 1�����Դ 2���۹�Դ
	bool lighton = true;		// �Ƿ�������

	glm::vec3 front;			// ���򣬻��߹�ķ���
	glm::vec3 position;			// λ��
	glm::vec3 velocity;
	glm::vec3 color = glm::vec3(1.0, 1.0, 1.0);			// ����ɫ
	glm::vec4 color_a = glm::vec4(1.0, 1.0, 1.0, 1.0);	// ��͸���ȵ���ɫ

	float constant;
	float linear;
	float quadratic;
	
	float cutOff;
	float outerCutOff;

	glm::vec3 ambientlight = XYY_DEFAULT_COLOR;
	glm::vec3 diffuselight = XYY_DEFAULT_COLOR;
	glm::vec3 specularlight = XYY_DEFAULT_COLOR;

	glm::vec4 ambientlight_a = XYY_DEFAULT_COLOR_A;
	glm::vec4 diffuselight_a = XYY_DEFAULT_COLOR_A;
	glm::vec4 specularlight_a = XYY_DEFAULT_COLOR_A;

	XYY_LocalLightDriver();
	void run(XYY_LocalRendDriver * lrd, unsigned int &dirlight_count, unsigned int &pointlight_count, unsigned int & spotlight_count);	// ���ƹ��Ч���ӵ�ele�� ���ֲ������ǲ���ֱ�Ӳ���element�ģ� �����ͳ�����ѭ�����ã����Խ��ܸ�element�ľֲ���Ⱦ����
	void run();		

	//�ù⳯���Ӧ�ĵ�
	void towardsat(glm::vec3 targetposition);
};