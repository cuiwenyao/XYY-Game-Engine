#pragma once
#include "GlobalVariable.h"

Camera* GlobalVariable::camerausing;
Scene* GlobalVariable::sceneusing;
Window* GlobalVariable::windowusing;
Camera* GlobalVariable::defaultcamera;
Shader* GlobalVariable::defaultobjectshader;
Window* GlobalVariable::defaultwindow;
GLFWimage GlobalVariable::icon;
SkyBox* GlobalVariable::skybox;
unsigned int GlobalVariable::objectscount=0;
unsigned int GlobalVariable::cubescount=0;
unsigned int GlobalVariable::planescount=0;