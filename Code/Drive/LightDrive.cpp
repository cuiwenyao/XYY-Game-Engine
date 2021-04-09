#pragma once
#include "LightDrive.h"
#include "../Variable/GlobalVariable.h"

void LightDrive::illuminate(Element* element,std::vector<Light* > lightlist)
{
    //设置光源的数量
    unsigned int dirlight_count = 0;
    //设置点光源的数量
    unsigned int pointlight_count = 0;
    //设置光源的数量
    unsigned int spotlight_count = 0;

	//光源 这里要判断是否可以影响得到
    for (int i=0;i<lightlist.size();i++)
    {
        //更新光源自身的信息。
        lightlist[i]->update();
        if (lightlist[i]->lighton)//判断是否可以影响得到
        {
            element->shader->use();
            element->shader->setVec3("viewPos", GlobalVariable::camerausing->position);
            element->shader->setFloat("shininess", 32.0f);
            if (lightlist[i]->type == 1)
            {
                //平行光
                std::string count = std::to_string(dirlight_count++);
                element->shader->setVec3(("dirLight["+count+"].direction").c_str(), lightlist[i]->front);
                element->shader->setVec3(("dirLight[" + count + "].color").c_str(), lightlist[i]->color);
                element->shader->setVec3(("dirLight[" + count + "].ambient").c_str(), lightlist[i]->ambientlight);
                element->shader->setVec3(("dirLight[" + count + "].diffuse").c_str(), lightlist[i]->diffuselight);
                element->shader->setVec3(("dirLight[" + count + "].specular").c_str(), lightlist[i]->specularlight);
            }
            else if (lightlist[i]->type == 2)
            {
                //点光源
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
                //聚光源
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


    //我在想要不要把声音与光当作是物体的属性。
    //将光源的数量传进去
    //std::cout << "渲染该物体的光源数量分别为" << "dirlight_count: " << dirlight_count << "pointlight_count: " << pointlight_count << "spotlight_count: " << spotlight_count << std::endl;
    element->shader->setInt("dirlight_count", dirlight_count);
    element->shader->setInt("pointlight_count", pointlight_count);
    element->shader->setInt("spotlight_count", spotlight_count);
    //物体的反光度
    element->shader->setInt("shininess", element->shininess);
}