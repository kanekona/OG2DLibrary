//
// �o�[�e�b�N�X�V�F�[�_�[
//

#version 450 

out vec4 color;
out vec2 uv;

in vec2 in_pos;
in vec4 in_color;

in vec2 in_uv;

void main()
{
	vec4 p = vec4(in_pos, 0.0, 1.0);
	gl_Position = p;
	color = in_color;
}
