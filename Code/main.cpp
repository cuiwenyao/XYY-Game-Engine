#include "XYY.h"
#include "Element/SkyBox.h"
#include "Element/Cube.h"
#include "Element/PointLight.h"
#include "Element/DirLight.h"
#include "Element/SpotLight.h"
int main()
{
    XYY::Init();

    Scene scene;

    GlobalVariable::camerausing = scene.camera;
    GlobalVariable::windowusing = scene.window;
    GlobalVariable::sceneusing = &scene;

    Object object1("resources/objects/nanosuit/nanosuit.obj"); 
    Object object2("resources/objects/spartan_armour_mkv_-_halo_reach/scene.gltf");
    Object object3("resources/objects/atomic_bomb_-_easter_freebie/scene.gltf");

    scene.addelement(&object1);
    scene.addelement(&object2);
    scene.addelement(&object3);
    

    //object2.Stretch(glm::vec3(0.01, 0.01, 0.01));
    //object2.move(glm::vec3(0, -1, 0));

    Cube cube;
    cube.attachtexture("resources/textures/container2.png", XYY_TEXTURE_TYPE_AMBIENT);
    cube.attachtexture("resources/textures/container2_specular.png", XYY_TEXTURE_TYPE_SPECULAR);
    cube.attachtexture("resources/textures/window.png.png", XYY_TEXTURE_TYPE_SPECULAR);
    
    cube.color = glm::vec3(1.0, 0.0, 0.0);
    scene.addelement(&cube);
    //cube.Stretch(glm::vec3(100, 0.001f, 100));
    //cube.move(glm::vec3(0, -1, 0));
    
    PointLight pointlight1;
    pointlight1.position = glm::vec3(5, 5, 5);

    scene.addlight(&pointlight1);

    DirLight dirlight1;

    scene.addlight(&dirlight1);
    SpotLight spotlight;
    scene.addlight(&spotlight);


    scene.run();
    glfwTerminate();
    return 0;
}