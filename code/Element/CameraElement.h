#pragma once

#include <glad/glad.h>
#include "Element.h"

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN,
	F,	//F���� G����
	G	
};

// Default camera values
const float YAW = 225.6f;
const float PITCH = -32.7f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

// xihang �� ��ô��������Ĳü��ռ�

/* ���Ԫ�ر�������һ�����ݽṹ��������ΪԪ�أ�Ҳ������Ϊ�������� */

// An abstract camera class __declspec(dllexport) that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class __declspec(dllexport) XYY_CameraElement : public XYY_Element //: public Element
{
public:
	// camera Attributes
	glm::vec3 position;
	
	glm::vec3 Front;		// ��� ǰ�򣨳��� �������ɵ�ǰ�� yaw��pitch ����Ϣ�������
	glm::vec3 Up;			// ��� ������
	glm::vec3 Right;		// ��� ������

	glm::vec3 WorldUp;		// ����涨�� �����Ϸ� ����
	
	// euler Angles
	float Yaw;
	float Pitch;

	// camera options
	float MovementSpeed;
	float MouseSensitivity;
	float Zoom;

	// constructor with vectors
	XYY_CameraElement(glm::vec3 position = glm::vec3(10.0f, 10.0f, 10.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
	// constructor with scalar values
	XYY_CameraElement(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);
	// returns the view matrix calculated using Euler Angles and the LookAt Matrix
	glm::mat4 GetViewMatrix();
	// processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
	void ProcessKeyboard(Camera_Movement direction, float deltaTime);
	// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
	void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
	// processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
	void ProcessMouseScroll(float yoffset);

private:
	// calculates the front vector from the Camera's (updated) Euler Angles
	void updateCameraVectors();
};
