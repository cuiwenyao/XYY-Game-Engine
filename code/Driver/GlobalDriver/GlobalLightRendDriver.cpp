#include "./GlobalLightRendDriver.h"


void XYY_GlobalLightRendDriver::init()
{

}

// ȫ����Ⱦ������ run() ����
void XYY_GlobalLightRendDriver::run( XYY_SceneContent * sc  )
{
	// ���
	XYY_CameraElement * cra;						// ������Ⱦʹ�õ����
	if (sc->Cameras.size() == 0) return;
	cra = (XYY_CameraElement *) sc->Cameras[0];		// ����Ӧ�ü�һ������飬���û���������Ⱦ

	// ���ȵƹ�ֲ�����
	for (int j = 0; j < sc->Lights.size(); ++j)
	{
		XYY_LocalLightDriver * lld = sc->Lights[j]->ld_light;
		lld->run();

		/* ����۹�λ�õĸ���Ӧ������һ����������� �� �ÿ�����һ�����巢�����ľ۹� */
		if (lld->type == 2)
		{
			lld->position = cra->position;
			lld->front = cra->Front;
		}
	}
	
	for (int i = 0; i < sc->Objects.size(); ++i)
	{
		// ��ȡele
		XYY_ObjectElement * ele = ( XYY_ObjectElement * )(sc->Objects[i]);
		XYY_LocalRendDriver  * lrd = ele->ld_rend;				// �ֲ���Ⱦ����

		// �ƹ�
		unsigned int dirlight_count = 0;		//���� ��Դ������
		unsigned int pointlight_count = 0;		//���� ���Դ������
		unsigned int spotlight_count = 0;		//���� ��Դ������
		for (int j = 0; j < sc->Lights.size(); ++j)
		{
			XYY_LocalLightDriver * lld = sc->Lights[j]->ld_light;			// �ֲ���������
			// run �ֲ���������
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

		// ���ø� ele �ľֲ���Ⱦ���� �� �漰��camera�Ĳ������൱�ڶ���ֲ���������Ҫ��ȫ���������
		lrd->viewmat = cra->GetViewMatrix();
		lrd->projectionmat = glm::perspective(glm::radians(cra->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 10000.0f);
		lrd->run();

	}

	// ��պ���Ⱦ
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