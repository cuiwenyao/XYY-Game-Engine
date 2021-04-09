#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H

#include "Light.h"

//
class SpotLight : public Light
{
public:
    SpotLight();
    void update();
};


#endif