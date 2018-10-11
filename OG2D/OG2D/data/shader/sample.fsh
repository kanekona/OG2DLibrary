//
// フラグメントシェーダー
//

#version 450
in vec4 color;
in vec2 uv;
out vec4 out_color;
out vec4 FragColor;
uniform sampler2D texture2d;
void main()
{
	out_color = color;
	FragColor = texture(texture2d,uv);
}
