//
// バーテックスシェーダー
//

#version 400

out vec2 uv;

in vec2 inpos;

//in mat4 viewMatrix;

in vec4 incolor;

out vec4 color;

in vec2 inuv;

void main()
{
	//vec4 p = vec4(in_pos, 0.0, 1.0);
	//gl_Position = vec4(inpos, 0.0, 1.0) * viewMatrix;
	gl_Position = vec4(inpos, 0.0, 1.0);
	uv = inuv;
	color = incolor;
}