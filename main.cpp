#include <iostream>
#include <string>

#include "./Code/Scene/Scene.h"

using namespace std;

int main()
{
	XYY_Scene * myscene = new XYY_Scene();
	myscene->sc->loadXML("scxml/ground.xml");
	
	myscene->run();

	return 0;
}