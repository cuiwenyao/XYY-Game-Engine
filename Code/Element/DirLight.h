#ifndef DIRLIGHT_H
#define DIRLIGHT_H

#include "Light.h"

//
class DirLight : public Light
{
public:
	DirLight();
	void update();
};


#endif