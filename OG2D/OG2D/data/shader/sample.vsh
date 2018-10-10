//
// バーテックスシェーダー
//

#version 450

in vec3 position;
in vec3 normal;
in vec4 color;

uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;

out vec3 e_normal;
out vec3 e_v;


void main()
{
	vec4 p = vec4(position, 1.0);
	gl_Position = projectionMatrix * modelViewMatrix * p;
	
	e_normal = vec3(modelViewMatrix * vec4(normal,0.0));
	e_v = (modelViewMatrix * vec4(position, 1.0)).xyz;
}
