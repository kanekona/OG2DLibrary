//
// フラグメントシェーダー
//

#version 400
in vec2 uv;

uniform sampler2D tex;

out vec4 outcolor;

in vec4 color;

void main()
{
	vec4 _co = texture2D(tex,uv);
	outcolor = vec4(color.x,color.y,color.z,color.w * _co.x);
}
