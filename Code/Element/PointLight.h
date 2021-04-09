#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Light.h"

//
class PointLight : public Light
{
public:
    PointLight();
    void update();
};


#endif