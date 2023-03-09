#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <Vertex.h>

class XYZ
{
public:
	XYZ();
	~XYZ();
	void draw();
	void init();

	std::vector<Vertex> vertex_holder;
	GLuint VAO, VBO;

	
};

