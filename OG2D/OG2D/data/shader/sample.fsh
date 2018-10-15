//
// フラグメントシェーダー
//

#version 400
in vec2 uv;
uniform sampler2D tex;
out vec4 flagColor;
void main()
{
	flagColor = texture2D(tex,uv);
}
