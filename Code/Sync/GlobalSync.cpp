#pragma once
#include "GlobalSync.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

float GlobalSync::currenttime;//��ǰʱ��
float GlobalSync::lasttime;//�ϴ�ͬ��ʱ��
float GlobalSync::deltatime;//ʱ���
float GlobalSync::targetfps;//Ŀ��֡��
float GlobalSync::currentfps;//��ǰ֡��
float GlobalSync::targetframetime;//Ŀ��֡ʱ��
float GlobalSync::currentframetime;//��ǰ֡ʱ��
float GlobalSync::mouselastX;//��������
float GlobalSync::mouselastY;//���������
bool GlobalSync::firstMouse = true;//����Ƿ��ǵ�һ��

void GlobalSync::update()
{
	currenttime = glfwGetTime();
	deltatime = currenttime - lasttime;
	currentframetime = deltatime;
	lasttime = currenttime;
	currentfps = 1.0 / deltatime;
}

