
#version 330 

layout (location = 0) in vec3 pos;
layout(location = 1) in vec4 color;

out vec4 Col;


void main()
{
	gl_Position = vec4(pos, 1.0f);
	
	Col = color;
}