#include "./Scene.h"
#include "../Resource/Window.h"
#include "../Driver/GlobalDriver/GlobalLightRendDriver.h"


XYY_Scene::XYY_Scene( XYY_Window * _win , XYY_SceneContent * _sc )
{
	this->win = _win;		// 窗口初始化
	this->sc  = _sc;		// 场景内容初始化	
	this->win->getwindow();

	// 创建全局驱动
	initGlobalDriver();

	// 加入一个默认的 相机
	this->sc->Cameras.push_back(new XYY_CameraElement());
	return;
}
XYY_Scene::XYY_Scene()
{
	XYY_Window * win_ = new XYY_Window(1920,1080, 3, 3);
	XYY_SceneContent * sc_ = new XYY_SceneContent();
	win_->getwindow();

	this->win = win_;	// 窗口初始化
	this->sc = sc_;		// 场景内容初始化	
	this->win->getwindow();

	// 创建全局驱动
	initGlobalDriver();
	
	// 加入一个默认的 相机
	this->sc->Cameras.push_back(new XYY_CameraElement());	
	
	return;
}


void XYY_Scene::run()
{
	win->start();	// 在Scene初始化的时候，窗口就已经建立了，该函数没有做什么工作

	// 完成各个全局驱动的初始化工作
	gd_sync->init();
	gd_io->init(win);
	gd_lightrend->init();
	gd_logic->init();
	gd_debugout->init();

	while ( !glfwWindowShouldClose( win->getwindow() ) )
	{
		//  清除场景信息 与 设置窗口    修改建议：这部分内容建议也 封装到窗口中间 ， 使实现更自由一些
		glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		// 调用该场景下的所有全局驱动
		gd_sync->run();					// 同步
		gd_io->run(sc,win,gd_sync);		// IO
		gd_logic->run(sc);				// 逻辑控制
		gd_lightrend->run(sc);			// 发光 & 渲染
		gd_debugout->run(sc);			// 调试

		// 更新窗口信息	修改建议：这部分内容建议也 封装到窗口中间 ， 使实现更自由一些
		glfwSwapBuffers( win->getwindow() );
		glfwPollEvents();
	}

	win->end();
}


void XYY_Scene::initGlobalDriver()
{
	gd_lightrend = new XYY_GlobalLightRendDriver();
	gd_io = new XYY_GlobalIODriver();
	gd_sync = new XYY_GlobalSyncDriver();
	gd_logic = new XYY_GlobalLogicDriver();
	gd_debugout = new XYY_GlobalDebugoutDriver();
	return;
}