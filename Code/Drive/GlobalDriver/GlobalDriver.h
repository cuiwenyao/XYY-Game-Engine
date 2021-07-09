#pragma once

#include "./../Driver.h"
#include "../../Scene/SceneContent.h"
#include "../LocalDriver/LocalRendDriver.h"
#include "../LocalDriver/LocalLightDriver.h"
// ... ������������־ֲ�������ʹ���е�ȫ�����������Է���ص��Ⱦֲ������ĺ���
#include "../../Element/Element.h"
#include "../../Element/ObjectElement.h"
#include "../../Element/CameraElement.h"
#include "../../Element/LightElement.h"
// ... �������������Ԫ�أ�ʹ���е�ȫ�����������Է���ص��ȸ���Ԫ��

// ... ���������������Դ


/*
д�����
	ȫ����������ʵ�ֳ�����ĳ�����幦�ܣ�����Ⱦ�����������ȡ�
	����Ҫ������๤����1��ͳ�ﳡ�������и���Element�ֲ����������ȫ������һ�µģ�������˳�� 2���������и����ֲ�����

һ�����⣺
	һ��ȫ������ ��� �����١� ��һ��Element�Ķ���ֲ������С��ҵ��� ���Լ�ƥ�䣨ʵ��ͳһ���ܣ����Ǹ��ֲ�������
		���������1�����ɣ�����ƥ���ȫ������ �� �ֲ�����֮�䶨���ʶ�� 2��ʹ�� ��������ʶ����
*/

/*
ȫ��������ŷ��䣺
0��GlobalLightRendDriver ������0��1�žֲ�������
*/

class XYY_GlobalDriver : public XYY_Driver
{
	public:
		int tag;
		void init();						// ��ʼ��
		void run(XYY_SceneContent * sc);	// ����


};