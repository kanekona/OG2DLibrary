//
// バーテックスシェーダー
//

#version 400

out vec2 uv;

in vec3 in_pos;

in mat4 in_viewMatrix;

in vec2 in_uv;

void main()
{
<<<<<<< HEAD
	//vec4 p = vec4(in_pos, 0.0, 1.0);
	gl_Position = vec4(in_pos, 1.0);
	uv = in_uv;
=======
	vec4 p = vec4(in_pos, 0.0, 1.0);
	gl_Position = in_viewMatrix * p;
	color = in_color;
>>>>>>> 63011734d9efc3448fe86589090a0c28e58d28e8
}
