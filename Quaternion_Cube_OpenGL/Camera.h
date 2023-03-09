#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/ext/matrix_transform.hpp>
#include <glm/glm/mat4x4.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
class Camera
{
public: 
	Camera();
	~Camera();
	glm::vec3 position;
	glm::vec3 view_direction;
	glm::vec3 up;
	glm::vec2 old_mouse_pos;
	
	void mouse_update(const glm::vec2 mouse_pos);
	glm::mat4 return_look_at();
};

