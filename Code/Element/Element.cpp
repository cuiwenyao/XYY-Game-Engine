#pragma once
#include "Element.h"

void Element::update()
{
	std::cout << "update in emement" << std::endl;
}
void Element::move(glm::vec3 translation)
{
	std::cout << "move in emement" << std::endl;
}
void Element::Stretch(glm::vec3 scale)
{
	std::cout << "Stretch in emement" << std::endl;
}
void Element::spin(float angle, glm::vec3 rotation)
{
	std::cout << "spin in emement" << std::endl;
}
