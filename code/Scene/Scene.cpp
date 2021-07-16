#include "./Scene.h"
#include "../Resource/Window.h"
#include "../Driver/GlobalDriver/GlobalLightRendDriver.h"


XYY_Scene::XYY_Scene( XYY_Window * _win , XYY_SceneContent * _sc )
{
	this->win = _win;		// ���ڳ�ʼ��
	this->sc  = _sc;		// �������ݳ�ʼ��	
	this->win->getwindow();

	// ����ȫ������
	initGlobalDriver();

	// ����һ��Ĭ�ϵ� ���
	this->sc->Cameras.push_back(new XYY_CameraElement());
	return;
}
XYY_Scene::XYY_Scene()
{
	XYY_Window * win_ = new XYY_Window(1920,1080, 3, 3);
	XYY_SceneContent * sc_ = new XYY_SceneContent();
	win_->getwindow();

	this->win = win_;	// ���ڳ�ʼ��
	this->sc = sc_;		// �������ݳ�ʼ��	
	this->win->getwindow();

	// ����ȫ������
	initGlobalDriver();
	
	// ����һ��Ĭ�ϵ� ���
	this->sc->Cameras.push_back(new XYY_CameraElement());	
	
	return;
}


void XYY_Scene::run()
{
	win->start();	// ��Scene��ʼ����ʱ�򣬴��ھ��Ѿ������ˣ��ú���û����ʲô����

	// ��ɸ���ȫ�������ĳ�ʼ������
	gd_sync->init();
	gd_io->init(win);
	gd_lightrend->init();
	gd_logic->init();
	gd_debugout->init();

	while ( !glfwWindowShouldClose( win->getwindow() ) )
	{
		//  ���������Ϣ �� ���ô���    �޸Ľ��飺�ⲿ�����ݽ���Ҳ ��װ�������м� �� ʹʵ�ָ�����һЩ
		glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		// ���øó����µ�����ȫ������
		gd_sync->run();					// ͬ��
		gd_io->run(sc,win,gd_sync);		// IO
		gd_logic->run(sc);				// �߼�����
		gd_lightrend->run(sc);			// ���� & ��Ⱦ
		gd_debugout->run(sc);			// ����

		// ���´�����Ϣ	�޸Ľ��飺�ⲿ�����ݽ���Ҳ ��װ�������м� �� ʹʵ�ָ�����һЩ
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