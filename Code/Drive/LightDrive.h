#ifndef LIGHTDRIVE_H
#define LIGHTDRIVE_H

#include "../Element/Element.h"
#include "../Element/Light.h"
//
class LightDrive
{
public:
	void illuminate(Element* element, std::vector<Light* > lightlist);

};


#endif