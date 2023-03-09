#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <Vertex.h>
class Cube
{public:
	Cube();
	~Cube();
	void draw();
	void init();

	std::vector<Vertex> vertex_holder;
	GLuint VAO, VBO;
};

