#version 330

layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_color;
layout(location = 2) in vec2 v_coord;
layout(location = 3) in vec3 v_normal;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform float Clock;

out vec2 frag_coord;
out vec3 frag_normal;
out vec3 frag_color;
out vec3 frag_position;

void main()
{
	
	frag_position = v_position;
	frag_color = v_color;
	frag_normal = Clock * v_normal;
	frag_coord = v_coord;

	gl_Position = Projection * View * Model * vec4(v_position, 1.0);
}
