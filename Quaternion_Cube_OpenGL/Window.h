#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <Shader.h>
#include <vector>
#include <XYZ.h>
#include <string>
#include <Cube.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/ext/matrix_transform.hpp>
#include <glm/glm/mat4x4.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
class Window
{
public:
	Window();
	~Window();

	GLint height = 1080, widht = 1920;
	const char* title{ "Guaternion Program" };
	int buffer_w, buffer_h;

	std::vector<Shader*> shader_list;
	XYZ* xyz = new XYZ();
	Cube* cube = new Cube();

	void init_meshes();
	void create_shaders();

	GLint _model_location;
	GLint _projection_location;
	GLint _rotation_location;
	GLint _view_location;
	GLint _scale_location;

};

