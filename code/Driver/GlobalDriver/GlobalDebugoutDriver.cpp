#include "GlobalDebugoutDriver.h"

void XYY_GlobalDebugoutDriver::init()
{
	turn = DEBUG_TURN;
}

void XYY_GlobalDebugoutDriver::run(XYY_SceneContent * sc)
{
	if (!turn) return;
	// �������������һЩ������Ϣ
	printFloatParameter("Camera - Yaw",sc->Cameras[0]->Yaw);
	printFloatParameter("Camera - Pitch", sc->Cameras[0]->Pitch);

	return;
}

void XYY_GlobalDebugoutDriver::printFloatParameter(std::string name, float v)
{
	std::cout << name << ":" << v << std::endl;
}