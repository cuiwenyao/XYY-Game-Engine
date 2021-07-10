#pragma once

#include "../Drive/GlobalDriver/GlobalDriver.h"
#include "../Drive/GlobalDriver/GlobalLightRendDriver.h"
#include "../Drive/GlobalDriver/GlobalIODriver.h"
#include "../Drive/GlobalDriver/GlobalSyncDriver.h"
#include "../Drive/GlobalDriver/GlobalLogicDriver.h"
#include "../Drive/GlobalDriver/GlobalDebugoutDriver.h"


class __declspec(dllexport) XYY_Scene
{
public:
	XYY_Window * win;						// ����������Թ���һ�����ڣ�����ʹ��ָ�� 

	XYY_SceneContent * sc;					// �������ݣ��������ݵ�ʵ�� ������ ����֮�� �� һ����������Ҳ���ܱ������������

	// ȫ������ʹ�ö�̬��ʽ���� �ǳ��鷳 �� ���Կ���ʹ�þ�̬����
	XYY_GlobalLightRendDriver * gd_lightrend;
	XYY_GlobalIODriver		  * gd_io;
	XYY_GlobalSyncDriver      * gd_sync;
	XYY_GlobalLogicDriver     * gd_logic;
	XYY_GlobalDebugoutDriver  * gd_debugout;
	
	XYY_Scene(XYY_Window * win, XYY_SceneContent * sc);
	XYY_Scene();						

	void run();								// ���иó���

private:
	void initGlobalDriver();				// ��������ȫ������

};
