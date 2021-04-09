#pragma once
#include "RendDrive.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../Variable/GlobalVariable.h"
#include "../Element/Object.h"

void RendDrive::rend(Element* element)
{
	if (element->type == 1)
	{
		element->viewmat = GlobalVariable::camerausing->GetViewMatrix();
		element->projectionmat = glm::perspective(glm::radians(GlobalVariable::camerausing->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		element->update();
		element->draw();
	}


}
