#include "Window.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/ext/matrix_transform.hpp>
#include <glm/glm/mat4x4.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include <XYZ.h>
#include <Camera.h>

GLFWwindow* window;
Camera* camera;

static const char* VShader = "vertex_shader.vert";
static const char* FShader = "fragment_shader.frag";

Window::Window()

{
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW." << std::endl;
		glfwTerminate();
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	window = glfwCreateWindow(widht, height, title, 0, 0);

	if (!window) {
		std::cout << "Failed to create a window" << std::endl;
	}

	glfwGetFramebufferSize(window, &buffer_w, &buffer_h);
	glfwMakeContextCurrent(window);
	

	glewExperimental = GL_TRUE;
	glewInit();

	

	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		glfwTerminate();
	}

	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, buffer_w, buffer_h);

	init_meshes();
	create_shaders();
	
	camera = new Camera(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT || GL_DEPTH_BUFFER_BIT);

		shader_list.at(0)->use_shader();
		glm::mat4 projection_matrix = glm::perspective(glm::radians(-90.0f), (GLfloat)buffer_w / (GLfloat)buffer_h, 0.1f, 100.0f);
		glm::mat4 view = camera->return_look_at();
		GLint project_loc = glGetUniformLocation(shader_list.at(0)->Shader_ID, "projection");
		GLint view_loc = glGetUniformLocation(shader_list.at(0)->Shader_ID, "view");
		glUniformMatrix4fv(project_loc, 1, GL_FALSE, glm::value_ptr(projection_matrix));
		glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));
		xyz->draw();

		
		shader_list.at(1)->use_shader();
		projection_matrix = glm::perspective(glm::radians(90.0f), (GLfloat)buffer_w / (GLfloat)buffer_h, 0.1f, 1.0f);
		 view = camera->return_look_at();
		 project_loc = glGetUniformLocation(shader_list.at(1)->Shader_ID, "projection");
		 view_loc = glGetUniformLocation(shader_list.at(0)->Shader_ID, "view");
		 glUniformMatrix4fv(project_loc, 1, GL_FALSE, glm::value_ptr(projection_matrix));
		glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));
		cube->draw();

		glUseProgram(0);
		glfwSwapBuffers(window);
	}
}




Window::~Window()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Window::init_meshes()
{
	
	xyz->init();
	cube->init();
}

void Window::create_shaders()
{
	Shader* shader_1 = new Shader();
	shader_1->create_from_file(VShader, FShader);
	shader_list.push_back(shader_1);

    Shader* shader_2 = new Shader();
    shader_2->create_from_file(VShader, FShader);
    shader_list.push_back(shader_2);
	
	
}
