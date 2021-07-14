#pragma once
#include "./CameraElement.h"
#include <iostream>
// constructor with vectors
XYY_CameraElement::XYY_CameraElement(glm::vec3 position, glm::vec3 up, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
{
	this->position = position;
	WorldUp = up;
	Yaw = yaw;
	Pitch = pitch;
	updateCameraVectors();
}
// constructor with scalar values
XYY_CameraElement::XYY_CameraElement(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
{
	this->position = glm::vec3(posX, posY, posZ);
	WorldUp = glm::vec3(upX, upY, upZ);
	Yaw = yaw;
	Pitch = pitch;
	updateCameraVectors();
}

// returns the view matrix calculated using Euler Angles and the LookAt Matrix
glm::mat4 XYY_CameraElement::GetViewMatrix()
{
	return glm::lookAt(this->position, this->position + Front, Up);
}

// processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
void XYY_CameraElement::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
	float velocity = MovementSpeed * deltaTime;
	
	if (direction == FORWARD)
		this->position += glm::vec3(Front.x * velocity, Front.y * velocity, Front.z * velocity);
	if (direction == BACKWARD)
		this->position -= glm::vec3(Front.x * velocity, Front.y * velocity, Front.z * velocity);
	if (direction == LEFT)
		this->position -= Right * velocity;
	if (direction == RIGHT)
		this->position += Right * velocity;
	if (direction == UP)
		this->position += Up * velocity;
	if (direction == DOWN)
		this->position -= Up * velocity;
	if (direction == F)
		this->MovementSpeed = std::min(30.0f , this->MovementSpeed + 0.1f );
	if (direction == G)
		this->MovementSpeed = std::max(0.0f, this->MovementSpeed - 0.1f);
}

// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void XYY_CameraElement::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
	xoffset *= MouseSensitivity;
	yoffset *= MouseSensitivity;

	Yaw += xoffset;
	Pitch += yoffset;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainPitch)
	{
		if (Pitch > 89.0f)
			Pitch = 89.0f;
		if (Pitch < -89.0f)
			Pitch = -89.0f;
	}

	// update Front, Right and Up Vectors using the updated Euler angles
	updateCameraVectors();
}

// processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
void XYY_CameraElement::ProcessMouseScroll(float yoffset)
{
	Zoom -= (float)yoffset;
	if (Zoom < 1.0f)
		Zoom = 1.0f;
	if (Zoom > 45.0f)
		Zoom = 45.0f;
}

void XYY_CameraElement::updateCameraVectors()
{
	// 由角度计算朝向，
	glm::vec3 front;
	front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	front.y = sin(glm::radians(Pitch));
	front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	Front = glm::normalize(front);

	// also re-calculate the Right and Up vector
	Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	Up = glm::normalize(glm::cross(Right, Front));

}