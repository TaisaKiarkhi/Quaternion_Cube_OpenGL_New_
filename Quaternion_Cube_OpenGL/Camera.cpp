#include "Camera.h"

Camera::Camera(glm::vec3 startPosition, glm::vec3 startUp)
{
	position = startPosition;
	worldUp = startUp;
	front = glm::vec3(0.0f, 0.0f, -1.0f);
	up = glm::vec3(0.0f, 0.0f, 1.0f);

}

Camera::~Camera()
{
}

glm::mat4 Camera::return_look_at()
{
	return glm::lookAt(position, position+front, up);
}
