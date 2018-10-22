//
// バーテックスシェーダー
//

#version 400

out vec2 uv;

in vec2 inpos;

uniform mat4 viewMatrix;

in vec4 incolor;

out vec4 color;

in vec2 inuv;

void main()
{
	gl_Position = vec4(inpos, 0.0, 1.0) * viewMatrix;
	uv = inuv;
	color = incolor;
}