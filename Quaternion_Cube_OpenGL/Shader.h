#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <iostream>
class Shader
{
public:
	Shader();
	~Shader();

	void create_from_file(const char* vertex_code, const char* fragment_code);
	std::string read_file(const char* file);
	void compile(const char* vertex, const char* fragment);
	void add_shader(GLuint shader_program, const char* code, GLenum shader_type);
	void use_shader();

	GLuint Shader_ID;


};

