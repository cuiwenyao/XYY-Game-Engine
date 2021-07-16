#include "./GlobalLogicDriver.h"

void XYY_GlobalLogicDriver::init(XYY_SceneContent* sc)
{
	// game init
	if(_initFunc) (*initFunc)(sc);
}

void XYY_GlobalLogicDriver::run(XYY_SceneContent * sc)
{
	// game running
	if(_runFunc) (*runFunc)(sc);
}

void XYY_GlobalLogicDriver::setInitFunc(void (*initFunc)(XYY_SceneContent* sc))
{
	this->_initFunc = true;
	this->initFunc = initFunc;
}

void XYY_GlobalLogicDriver::setRunFunc(void (*runFunc)(XYY_SceneContent* sc))
{
	this->_runFunc = true;
	this->runFunc = runFunc;
}