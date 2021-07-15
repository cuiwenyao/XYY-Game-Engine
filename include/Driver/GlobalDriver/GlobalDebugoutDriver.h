#pragma once
#include "./GlobalDriver.h"

#define DEBUG_TURN false		// DEBUG ¿ª¹Ø

class   XYY_GlobalDebugoutDriver : XYY_GlobalDriver
{
public:
	bool turn = DEBUG_TURN;
	void init();
	void run(XYY_SceneContent * sc);

private:
	static void printFloatParameter(std::string name,float v);
};