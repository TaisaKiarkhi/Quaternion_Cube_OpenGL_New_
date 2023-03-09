#include "Shader.h"
#include <stdio.h>
Shader::Shader()
{
	Shader_ID = 0;
}

Shader::~Shader()
{
	if (Shader_ID != 0) {
		glDeleteShader(Shader_ID);
		Shader_ID = 0;
	}
}

void Shader::create_from_file(const char* vertex_code, const char* fragment_code)
{
	std::string vertex_s = read_file(vertex_code);
	std::string fragment_s = read_file(fragment_code);

	const char* Vertex_read_code = vertex_s.c_str();
	const char* Fragment_read_code = fragment_s.c_str();

	compile(Vertex_read_code, Fragment_read_code);
}

std::string Shader::read_file(const char* file)
{
	std::string content;
	std::fstream inn_file(file, std::ios::in);

	if (!inn_file.is_open()) {
		//printf("Failed to read %s! File doesn't exist.", inn_file);
		return "";
	}
	std::string line = " ";

	while (!inn_file.eof()) {
		std::getline(inn_file, line);
		content.append(line + "\n");
	}
	inn_file.close();
	return content;
}

void Shader::compile(const char* vertex, const char* fragment)
{
	Shader_ID = glCreateProgram();
	if (!Shader_ID) {
		std::cout<< "Failed to create a program" << std::endl;
	}

	add_shader(Shader_ID, vertex, GL_VERTEX_SHADER);
	add_shader(Shader_ID, fragment, GL_FRAGMENT_SHADER);

	GLint result = 0;
	GLchar log_message[1024]={0};

	glLinkProgram(Shader_ID);
	glGetProgramiv(Shader_ID, GL_LINK_STATUS, &result);
    if (!result) {
		glGetProgramInfoLog(Shader_ID, sizeof(log_message), NULL, log_message);
		std::cout << "Failed to link the program" << std::endl;
	}
	
	glValidateProgram(Shader_ID);
	glGetProgramiv(Shader_ID, GL_VALIDATE_STATUS, &result);
	if (!result) {
		glGetProgramInfoLog(Shader_ID, sizeof(log_message), NULL, log_message);
		std::cout << "Failed to validate the program" << std::endl;
	}


}

void Shader::add_shader(GLuint shader_program, const char* code, GLenum shader_type)
{
	GLuint Shader = glCreateShader(shader_type);
	const char* the_shader_code[1];
	the_shader_code[0] = code;

	GLint code_lenght[1];
	code_lenght[0] = strlen(code);

	glShaderSource(Shader, 1, the_shader_code, code_lenght);
	glCompileShader(Shader);


	GLint result = 0;
	GLchar log_message[1024]={0};

	glGetShaderiv(Shader, GL_COMPILE_STATUS, &result);
	if (!result) {
		glGetShaderInfoLog(Shader, sizeof(log_message), NULL, log_message);
		printf("Error compiling the %d shader: '%s'\n", shader_type, log_message);
		return;
	}
	glAttachShader(shader_program, Shader);
}

void Shader::use_shader()
{
	glUseProgram(Shader_ID);
}
