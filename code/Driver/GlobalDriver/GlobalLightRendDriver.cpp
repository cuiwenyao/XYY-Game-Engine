#include "./GlobalLightRendDriver.h"


void XYY_GlobalLightRendDriver::init()
{

}

// 全局渲染驱动的 run() 函数
void XYY_GlobalLightRendDriver::run( XYY_SceneContent * sc  )
{
	// 相机
	XYY_CameraElement * cra;						// 本次渲染使用的相机
	if (sc->Cameras.size() == 0) return;
	cra = (XYY_CameraElement *) sc->Cameras[0];		// 这里应该加一个差错检查，如果没有相机则不渲染

	// 调度灯光局部驱动
	for (int j = 0; j < sc->Lights.size(); ++j)
	{
		XYY_LocalLightDriver * lld = sc->Lights[j]->ld_light;
		lld->run();

		/* 下面聚光位置的更新应更有另一个驱动来完成 ， 得看是哪一个物体发出来的聚光 */
		if (lld->type == 2)
		{
			lld->position = cra->position;
			lld->front = cra->Front;
		}
	}
	
	for (int i = 0; i < sc->Objects.size(); ++i)
	{
		// 获取ele
		XYY_ObjectElement * ele = ( XYY_ObjectElement * )(sc->Objects[i]);
		XYY_LocalRendDriver  * lrd = ele->ld_rend;				// 局部渲染驱动

		// 灯光
		unsigned int dirlight_count = 0;		//设置 光源的数量
		unsigned int pointlight_count = 0;		//设置 点光源的数量
		unsigned int spotlight_count = 0;		//设置 光源的数量
		for (int j = 0; j < sc->Lights.size(); ++j)
		{
			XYY_LocalLightDriver * lld = sc->Lights[j]->ld_light;			// 局部发光驱动
			// run 局部发光驱动
			if (lld->lighton)
			{
				lrd->shader->use();
				lrd->shader->setVec3("viewPos", cra->position);
				lrd->shader->setFloat("shininess", 32.0f);
				lld->run(lrd, dirlight_count, pointlight_count, spotlight_count);
			}
		}
		lrd->shader->setInt("dirlight_count", dirlight_count);
		lrd->shader->setInt("pointlight_count", pointlight_count);
		lrd->shader->setInt("spotlight_count", spotlight_count);
		lrd->shader->setInt("shininess", lrd->shininess);

		// 调用该 ele 的局部渲染驱动 ， 涉及到camera的操作（相当于多个局部交互）需要由全局驱动完成
		lrd->viewmat = cra->GetViewMatrix();
		lrd->projectionmat = glm::perspective(glm::radians(cra->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 10000.0f);
		lrd->run();

	}

	// 天空盒渲染
	if (sc->skybox != NULL)
	{
		XYY_LocalRendDriver  * lrd = sc->skybox->ld_rend;
		lrd->shader->use();
		lrd->modelmat = glm::mat4(1.0f);
		lrd->viewmat = glm::mat4(glm::mat3(cra->GetViewMatrix())); // remove translation from the view matrix
		lrd->projectionmat = glm::perspective(glm::radians(cra->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		lrd->run();
	}
	

}