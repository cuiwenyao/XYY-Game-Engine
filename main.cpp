#include <iostream>
#include <string>

#include <Scene/Scene.h>

using namespace std;

int main()
{
	XYY_Scene * myscene = new XYY_Scene();
	myscene->sc->loadXML("include/Scxmlexample/coordinate.xml");
	myscene->run();
	return 0;
}