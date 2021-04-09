#ifndef LIGHT_H
#define LIGHT_H

#include "Element.h"

//����ֻ�ṩ������Ϣ������ʵʱ���ṩλ�ã�������ɫ�Ϳ���������������Ϣ������Ҫ��Ⱦ������Ҫshader.
class Light
{
public:

	float speed = 10;//�ٶ�
	unsigned int type = 0;//// 1��ƽ�й� 2�����Դ 3���۹�Դ
	bool lighton = true;//�Ƿ�������

	glm::vec3 front;//���򣬻��߹�ķ���
	glm::vec3 position;//λ��
	glm::vec3 velocity;
	glm::vec3 color = glm::vec3(1.0, 1.0, 1.0);//����ɫ
	glm::vec4 color_a = glm::vec4(1.0, 1.0, 1.0, 1.0);//��͸���ȵ���ɫ

	float constant;
	float linear;
	float quadratic;
	float cutOff;
	float outerCutOff;

	glm::vec3 ambientlight = glm::vec3(1.0, 1.0, 1.0);
	glm::vec3 diffuselight = glm::vec3(1.0, 1.0, 1.0);
	glm::vec3 specularlight = glm::vec3(1.0, 1.0, 1.0);

	glm::vec4 ambientlight_a = glm::vec4(1.0, 1.0, 1.0, 1.0);
	glm::vec4 diffuselight_a = glm::vec4(1.0, 1.0, 1.0, 1.0);
	glm::vec4 specularlight_a = glm::vec4(1.0, 1.0, 1.0, 1.0);


	Light();

	//�ù⳯���Ӧ�ĵ�
	void towardsat(glm::vec3 targetposition);

	virtual void update() = 0;
};


#endif