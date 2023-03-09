#include "Vertex.h"

Vertex::Vertex(float x, float y, float z, float r, float g, float b)
{
	xyz_values = glm::vec3(x, y, z);
	rgb_values = glm::vec3(r, g, b);
}


