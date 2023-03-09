
#version 330 

layout (location = 0) in vec3 pos;
layout(location = 1) in vec4 color;

uniform mat4 view;
uniform mat4 projection;
out vec4 Col;


void main()
{
	gl_Position = projection*view*vec4(pos, 1.0f);
	
	Col = color;
}