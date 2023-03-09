#include "Cube.h"

Cube::Cube()
{
	vertex_holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,        1.0f, 0.0f, 1.0f });
	vertex_holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,         1.0f, 0.0f, 1.0f });
	vertex_holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,         0.0f, 1.0f, 1.0f });
	vertex_holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,         0.0f, 1.0f, 1.0f });
	vertex_holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,       0.561f, 0.0f, 1.0f });
	vertex_holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,       0.561f, 0.0f, 1.0f });
	
	vertex_holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,          1.0f, 0.0f, 1.0f  });
	vertex_holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,           1.0f, 0.0f, 1.0f  });
	vertex_holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,           0.0f, 1.0f, 1.0f  });
	vertex_holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,           0.0f, 1.0f, 1.0f  });
	vertex_holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,         0.561f, 0.0f, 1.0f });
	vertex_holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,         0.561f, 0.0f, 1.0f });
	
	vertex_holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,          1.0f, 0.0f, 1.0f });
	vertex_holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,          1.0f, 0.0f, 1.0f });
	vertex_holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,          0.0f, 1.0f, 1.0f });
	vertex_holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,          0.0f, 1.0f, 1.0f });
	vertex_holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,         0.561f, 0.0f, 1.0f});
	vertex_holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,         0.561f, 0.0f, 1.0f});

	vertex_holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,           1.0f, 0.0f, 1.0f });
	vertex_holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,           1.0f, 0.0f, 1.0f });
	vertex_holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,           0.0f, 1.0f, 1.0f });
	vertex_holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,           0.0f, 1.0f, 1.0f });
	vertex_holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,          0.561f, 0.0f, 1.0f});
	vertex_holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,          0.561f, 0.0f, 1.0f});

	vertex_holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,          1.0f, 0.0f, 1.0f  });
	vertex_holder.push_back(Vertex{ 0.5f, -0.5f, -0.5f,           1.0f, 0.0f, 1.0f  });
	vertex_holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,           0.0f, 1.0f, 1.0f  });
	vertex_holder.push_back(Vertex{ 0.5f, -0.5f,  0.5f,           0.0f, 1.0f, 1.0f  });
	vertex_holder.push_back(Vertex{ -0.5f, -0.5f,  0.5f,         0.561f, 0.0f, 1.0f });
	vertex_holder.push_back(Vertex{ -0.5f, -0.5f, -0.5f,         0.561f, 0.0f, 1.0f });
	//rm of the roof									 878		  1
	vertex_holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,         1.0f, 0.0f, 1.0f });
	vertex_holder.push_back(Vertex{ 0.5f,  0.5f, -0.5f,          1.0f, 0.0f, 1.0f });
	vertex_holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,          0.0f, 1.0f, 1.0f });
	vertex_holder.push_back(Vertex{ 0.5f,  0.5f,  0.5f,          0.0f, 1.0f, 1.0f });
	vertex_holder.push_back(Vertex{ -0.5f,  0.5f,  0.5f,        0.561f, 0.0f, 1.0f});
	vertex_holder.push_back(Vertex{ -0.5f,  0.5f, -0.5f,        0.561f, 0.0f, 1.0f});
}

Cube::~Cube()
{

}

void Cube::draw()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glDrawArrays(GL_TRIANGLES, 0, vertex_holder.size());
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Cube::init()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertex_holder.size(), vertex_holder.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));

	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
