//
// バーテックスシェーダー
//

#version 400

out vec2 uv;

in vec3 in_pos;

in vec2 in_uv;

void main()
{
	//vec4 p = vec4(in_pos, 0.0, 1.0);
	gl_Position = vec4(in_pos, 1.0);
	uv = in_uv;
}
