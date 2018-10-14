//
// フラグメントシェーダー
//

#version 400
in vec2 uv;
uniform sampler2D texture2d;
void main()
{
	gl_FragColor = texture2D(texture2d,uv);
}
