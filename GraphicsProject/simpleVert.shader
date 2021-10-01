// A simple vertex shader
#version 410

layout(location = 0) in vec4 position;
layout(location = 1) in color vColor;

uniform mat4 projectionViewModel;

out vec4 color;

void main()
{
	color = vColor;
	gl_Position = projectionViewModel * position;
}