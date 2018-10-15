//
// フラグメントシェーダー
//

#version 400
in vec2 uv;
uniform sampler2D tex;
out vec4 outcolor;
void main()
{
	outcolor = texture2D(tex,uv);
}
