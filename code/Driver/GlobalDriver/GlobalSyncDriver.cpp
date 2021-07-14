#include "./GlobalSyncDriver.h"
#include "../../Resource/Window.h"

XYY_GlobalSyncDriver::XYY_GlobalSyncDriver()
{
	
}

void XYY_GlobalSyncDriver::init()
{
	lasttime = glfwGetTime();
}

void XYY_GlobalSyncDriver::run()
{
	currenttime = glfwGetTime();
	deltatime = currenttime - lasttime;
	currentframetime = deltatime;
	lasttime = currenttime;
	currentfps = 1.0 / deltatime;
}