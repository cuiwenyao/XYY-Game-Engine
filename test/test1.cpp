#include <iostream>
#include <string>
#include <Scene/Scene.h>
int main()
{
	XYY_Window* mywin = new XYY_Window(800, 600, false);
	XYY_SceneContent* mysc = new XYY_SceneContent();
	XYY_Scene* myscene = new XYY_Scene(mywin, mysc);
	myscene->sc->loadXML("include/Scxmlexample/starskybox.xml");
	myscene->run();
	return 0;
}