#pragma once
#include "LightDrive.h"
#include "../Variable/GlobalVariable.h"

void LightDrive::illuminate(Element* element,std::vector<Light* > lightlist)
{
    //���ù�Դ������
    unsigned int dirlight_count = 0;
    //���õ��Դ������
    unsigned int pointlight_count = 0;
    //���ù�Դ������
    unsigned int spotlight_count = 0;

	//��Դ ����Ҫ�ж��Ƿ����Ӱ��õ�
    for (int i=0;i<lightlist.size();i++)
    {
        //���¹�Դ�������Ϣ��
        lightlist[i]->update();
        if (lightlist[i]->lighton)//�ж��Ƿ����Ӱ��õ�
        {
            element->shader->use();
            element->shader->setVec3("viewPos", GlobalVariable::camerausing->position);
            element->shader->setFloat("shininess", 32.0f);
            if (lightlist[i]->type == 1)
            {
                //ƽ�й�
                std::string count = std::to_string(dirlight_count++);
                element->shader->setVec3(("dirLight["+count+"].direction").c_str(), lightlist[i]->front);
                element->shader->setVec3(("dirLight[" + count + "].color").c_str(), lightlist[i]->color);
                element->shader->setVec3(("dirLight[" + count + "].ambient").c_str(), lightlist[i]->ambientlight);
                element->shader->setVec3(("dirLight[" + count + "].diffuse").c_str(), lightlist[i]->diffuselight);
                element->shader->setVec3(("dirLight[" + count + "].specular").c_str(), lightlist[i]->specularlight);
            }
            else if (lightlist[i]->type == 2)
            {
                //���Դ
                std::string count = std::to_string(pointlight_count++);
                element->shader->setVec3("pointLight["+count+"].position", lightlist[i]->position);
                element->shader->setVec3(("pointLight[" + count + "].color").c_str(), lightlist[i]->color);
                element->shader->setVec3("pointLight[" + count + "].ambient", lightlist[i]->ambientlight);
                element->shader->setVec3("pointLight[" + count + "].diffuse", lightlist[i]->diffuselight);
                element->shader->setVec3("pointLight[" + count + "].specular", lightlist[i]->specularlight);
                element->shader->setFloat("pointLight[" + count + "].constant", lightlist[i]->constant);
                element->shader->setFloat("pointLight[" + count + "].linear", lightlist[i]->linear);
                element->shader->setFloat("pointLight[" + count + "].quadratic", lightlist[i]->quadratic);
            }
            else if (lightlist[i]->type == 3)
            {
                //�۹�Դ
                std::string count = std::to_string(spotlight_count++);
                element->shader->setVec3(("spotLight[" + count + "].direction").c_str(), lightlist[i]->front);
                element->shader->setVec3(("spotLight[" + count + "].color").c_str(), lightlist[i]->color);
                element->shader->setVec3("spotLight[" + count + "].position", lightlist[i]->position);
                element->shader->setVec3("spotLight[" + count + "].ambient", lightlist[i]->ambientlight);
                element->shader->setVec3("spotLight[" + count + "].diffuse", lightlist[i]->diffuselight);
                element->shader->setVec3("spotLight[" + count + "].specular", lightlist[i]->specularlight);
                element->shader->setFloat("spotLight[" + count + "].constant", lightlist[i]->constant);
                element->shader->setFloat("spotLight[" + count + "].linear", lightlist[i]->linear);
                element->shader->setFloat("spotLight[" + count + "].quadratic", lightlist[i]->quadratic);
                element->shader->setFloat("spotLight[" + count + "].cutOff", lightlist[i]->cutOff);
                element->shader->setFloat("spotLight[" + count + "].outerCutOff", lightlist[i]->outerCutOff);
            }
        }
    }


    //������Ҫ��Ҫ��������⵱������������ԡ�
    //����Դ����������ȥ
    //std::cout << "��Ⱦ������Ĺ�Դ�����ֱ�Ϊ" << "dirlight_count: " << dirlight_count << "pointlight_count: " << pointlight_count << "spotlight_count: " << spotlight_count << std::endl;
    element->shader->setInt("dirlight_count", dirlight_count);
    element->shader->setInt("pointlight_count", pointlight_count);
    element->shader->setInt("spotlight_count", spotlight_count);
    //����ķ����
    element->shader->setInt("shininess", element->shininess);
}