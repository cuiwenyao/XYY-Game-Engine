#pragma once

#include "../Driver/GlobalDriver/GlobalDriver.h"
#include "../Driver/GlobalDriver/GlobalLightRendDriver.h"
#include "../Driver/GlobalDriver/GlobalIODriver.h"
#include "../Driver/GlobalDriver/GlobalSyncDriver.h"
#include "../Driver/GlobalDriver/GlobalLogicDriver.h"
#include "../Driver/GlobalDriver/GlobalDebugoutDriver.h"

class   XYY_Scene
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
