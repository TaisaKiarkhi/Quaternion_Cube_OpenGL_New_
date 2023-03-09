#include "XYZ.h"

XYZ::XYZ()
{
vertex_holder.push_back(Vertex{ 0.0f ,0.0f ,   0.0f,         1.0f,  0.0f,  0.0f });
vertex_holder.push_back(Vertex{ 1000.0f ,0.0f, 0.0f,      1.0f,  0.0f,  0.0f });
vertex_holder.push_back(Vertex{ 0.0f ,0.0f ,   0.0f,         0.0f,  1.0f,  0.0f });
vertex_holder.push_back(Vertex{ 0.0f ,1000.0f ,0.0f,      0.0f,  1.0f,  0.0f });
vertex_holder.push_back(Vertex{ 0.0f ,0.0f ,   0.0f,         0.0f,  0.0f,  1.0f });
vertex_holder.push_back(Vertex{ 0.0f ,0.0f ,   1000.0f,      0.0f,  0.0f,  1.0f });
vertex_holder.push_back(Vertex{ 0.0f ,0.0f ,   0.0f,         1.0f,  0.0f,  0.0f });

vertex_holder.push_back(Vertex{ 0.0f ,1000.0f ,0.0f,      0.0f,  1.0f,  0.0f });
vertex_holder.push_back(Vertex{ 0.0f ,0.0f ,   0.0f,         1.0f,  0.0f,  0.0f });
vertex_holder.push_back(Vertex{ -1000.0f ,0.0f,0.0f,       1.0f  ,0.0f  ,0.0f });
vertex_holder.push_back(Vertex{ 0.0f  ,0.0f  , 0.0f,       0.0f  ,1.0f  ,0.0f });
vertex_holder.push_back(Vertex{ 0.0f ,-1000.0f,0.0f,     0.0f  ,1.0f  ,0.0f });
vertex_holder.push_back(Vertex{ 0.0f  ,0.0f  , 0.0f,       0.0f  ,0.0f  ,1.0f });
vertex_holder.push_back(Vertex{ 0.0f  ,0.0f ,-1000.0f,    0.0f  ,0.0f  ,1.0f });

//vertex_holder.push_back(Vertex{ 0,0,0,1,0,0 });
//vertex_holder.push_back(Vertex{ 6,0,0,1,0,0 });
//vertex_holder.push_back(Vertex{ 0,0,0,0,1,0 });
//vertex_holder.push_back(Vertex{ 0,6,0,0,1,0 });
//vertex_holder.push_back(Vertex{ 0,0,0,0,0,0 });
//vertex_holder.push_back(Vertex{ 0,0,6,0,0,0 });
//
//vertex_holder.push_back(Vertex{ 0,0,0,1,0,0 });
//vertex_holder.push_back(Vertex{ -6,0,0,1,0,0 });
//vertex_holder.push_back(Vertex{ 0,0,0,0,1,0 });
//vertex_holder.push_back(Vertex{ 0,-6,0,0,1,0 });
//vertex_holder.push_back(Vertex{ 0,0,0,0,0,0 });
//vertex_holder.push_back(Vertex{ 0,0,-6,0,0,0 });



}

XYZ::~XYZ()
{
	if (VBO != 0) {
		glDeleteBuffers(1, &VBO);
		VBO = 0;
	}


	if (VAO != 0) {
		glDeleteVertexArrays(1, &VAO);
		VAO = 0;
	}
}

void XYZ::draw()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glDrawArrays(GL_LINES, 0, vertex_holder.size());
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);
}

void XYZ::init()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertex_holder.size(), vertex_holder.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);




}
