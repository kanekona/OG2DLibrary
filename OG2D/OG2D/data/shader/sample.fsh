//
// �t���O�����g�V�F�[�_�[
//

//#version 400
in vec2 uv;
uniform sampler2D tex;

void main()
{
	gl_FragColor = texture2D(tex,uv);
}
