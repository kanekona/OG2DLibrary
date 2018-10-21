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
	vec4 _co = texture2D(tex,uv) * color;
	if(_co == vec4(0,0,0,1))
	{
		_co.w = 0.0;
	}
	 outcolor = _co;
}
