## 使用

### 从源码进行

#### make

需要你的电脑上有cmake并且保证版本再 3.20 以上

在下载的源文件根目录使用cmake进行premake

```
cmake -S ./ -B build
```

当然如果你不想使用命令行的话，可以自行使用cmake提供的GUI版本进行可视化操作。

premake之后，会在根目录生成一个build文件夹并在其中生成XYY_Game_Engine项目，打开这个下项目，并生成你所需要的解决方案即可。在使用test之前必须对install进行生成以安装运行依赖。

完整的源码版本还会生成test项目，这是XYY_Game_Engine的使用示例，你可以直接运行。

想要重新开始自己的工程？请参照 **使用release开发**。其中release所需要的文件由XYY_Game_Engine和install两个解决方案生成

### 使用release开发


下载release包并解压。

将解压生成的bin文件夹内的两个dll文件放在项目的根目录或者你的可执行文件同目录下。

将include文件夹以及contrib/include文件夹设置为项目的包含目录。

将lib文件夹设置为项目的库目录。

在项目中添加依赖XYY_Game_Engine.lib

添加源文件  示例：

```c++
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
```






