#include "Camera.h"

Camera::Camera()
{
	position = glm::vec3(2.0f, 2.0f, 5.0f);
	view_direction = glm::vec3(0.0f, 0.0f, -2.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);

}

Camera::~Camera()
{
}

void Camera::mouse_update(const glm::vec2 mouse_pos)
{
	glm::vec2 mouse_delta = mouse_pos - old_mouse_pos;
	view_direction = glm::mat3(glm::rotate(glm::mat4(1.0f), 0.0f, (glm::radians(mouse_delta.x), up )))*view_direction;
	old_mouse_pos = mouse_pos;
}

glm::mat4 Camera::return_look_at()
{
	return glm::lookAt(position, position + view_direction, up);
}
