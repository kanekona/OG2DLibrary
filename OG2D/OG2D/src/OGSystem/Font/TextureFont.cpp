#include "TextureFont.h"

Font::Font()
	:TexFontSize(Vec2(70.f,71.f))
{
	this->fontTex = new Texture("A2.png");
	this->CreateCharacter();
}
Font::~Font()
{
	delete this->fontTex;
}
void Font::Draw(const std::string& text,const Vec2& pos,const int fontSize)
{
	//�ێ��f�[�^��������
	this->texSize = 0;
	this->drawText = text;
	//�����񂪂Ȃ��Ȃ�܂Ń��[�v
	while (!this->drawText.empty())
	{
		//�擪���������o�C�g�Ȃ̂����ׂ�
		switch (OG::mbclen(this->drawText.substr(0, 1).c_str()))
		{
		case 2: //2byte
			//�`��ʒu�w��
			this->draw = Box2D(pos.x + (fontSize * this->texSize), pos.y,
				(float)fontSize, (float)fontSize);
			//�t�H���g�f�[�^���擾
			this->src = this->CharacterCheck(this->drawText.substr(0, 2));
			if (this->src)
			{
				this->draw.OffsetSize();
				this->fontTex->Draw(this->draw, *this->src);
			}
			//�`����I���������������
			this->drawText.erase(0, 2);
			break;
		case 1: //1byte
			//�`��ʒu�w��
			this->draw = Box2D(pos.x + (fontSize * this->texSize), pos.y, (float)fontSize, (float)fontSize);
			//�t�H���g�f�[�^���擾
			this->src = this->CharacterCheck(this->drawText.substr(0, 1));
			if (this->src)
			{
				this->draw.OffsetSize();
				this->fontTex->Draw(this->draw, *this->src);
			}
			//�`����I���������������
			this->drawText.erase(0, 1);
			break;
		default: //��O�G���[(space�Ƃ��ď���)
			break;
		}
		++this->texSize;
	}
}
Box2D* Font::CharacterCheck(const std::string& c)
{
	if (this->func.find(c) != this->func.end())
	{
		//std::map�̌�����hit�������̂�Ԃ�
		return &this->func[c];
	}
	//������Ȃ������ꍇnullptr
	//�����݉��A�ǂݍ��݂Ɏ��s������?��Ԃ��悤�ɂ���
	return nullptr;
}
void Font::CreateCharacter()
{
	//�t�H���g�f�[�^����
	this->func.insert(std::make_pair("a", Box2D(this->TexFontSize.x * 0 , this->TexFontSize.y * 0, this->TexFontSize.x * 1 , this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("b", Box2D(this->TexFontSize.x * 1 , this->TexFontSize.y * 0, this->TexFontSize.x * 2 , this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("c", Box2D(this->TexFontSize.x * 2 , this->TexFontSize.y * 0, this->TexFontSize.x * 3 , this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("d", Box2D(this->TexFontSize.x * 3 , this->TexFontSize.y * 0, this->TexFontSize.x * 4 , this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("e", Box2D(this->TexFontSize.x * 4 , this->TexFontSize.y * 0, this->TexFontSize.x * 5 , this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("f", Box2D(this->TexFontSize.x * 5 , this->TexFontSize.y * 0, this->TexFontSize.x * 6 , this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("g", Box2D(this->TexFontSize.x * 6 , this->TexFontSize.y * 0, this->TexFontSize.x * 7 , this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("h", Box2D(this->TexFontSize.x * 7 , this->TexFontSize.y * 0, this->TexFontSize.x * 8 , this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("i", Box2D(this->TexFontSize.x * 8 , this->TexFontSize.y * 0, this->TexFontSize.x * 9 , this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("j", Box2D(this->TexFontSize.x * 9 , this->TexFontSize.y * 0, this->TexFontSize.x * 10, this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("k", Box2D(this->TexFontSize.x * 10, this->TexFontSize.y * 0, this->TexFontSize.x * 11, this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("l", Box2D(this->TexFontSize.x * 11, this->TexFontSize.y * 0, this->TexFontSize.x * 12, this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("m", Box2D(this->TexFontSize.x * 12, this->TexFontSize.y * 0, this->TexFontSize.x * 13, this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("n", Box2D(this->TexFontSize.x * 13, this->TexFontSize.y * 0, this->TexFontSize.x * 14, this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("o", Box2D(this->TexFontSize.x * 14, this->TexFontSize.y * 0, this->TexFontSize.x * 15, this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("p", Box2D(this->TexFontSize.x * 15, this->TexFontSize.y * 0, this->TexFontSize.x * 16, this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("q", Box2D(this->TexFontSize.x * 16, this->TexFontSize.y * 0, this->TexFontSize.x * 17, this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("r", Box2D(this->TexFontSize.x * 17, this->TexFontSize.y * 0, this->TexFontSize.x * 18, this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("s", Box2D(this->TexFontSize.x * 18, this->TexFontSize.y * 0, this->TexFontSize.x * 19, this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("t", Box2D(this->TexFontSize.x * 19, this->TexFontSize.y * 0, this->TexFontSize.x * 20, this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("u", Box2D(this->TexFontSize.x * 20, this->TexFontSize.y * 0, this->TexFontSize.x * 21, this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("v", Box2D(this->TexFontSize.x * 21, this->TexFontSize.y * 0, this->TexFontSize.x * 22, this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("w", Box2D(this->TexFontSize.x * 22, this->TexFontSize.y * 0, this->TexFontSize.x * 23, this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("x", Box2D(this->TexFontSize.x * 23, this->TexFontSize.y * 0, this->TexFontSize.x * 24, this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("y", Box2D(this->TexFontSize.x * 24, this->TexFontSize.y * 0, this->TexFontSize.x * 25, this->TexFontSize.y * 1)));
	this->func.insert(std::make_pair("z", Box2D(this->TexFontSize.x * 25, this->TexFontSize.y * 0, this->TexFontSize.x * 26, this->TexFontSize.y * 1)));

	this->func.insert(std::make_pair("A", Box2D(this->TexFontSize.x * 0 , this->TexFontSize.y * 1, this->TexFontSize.x * 1 , this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("B", Box2D(this->TexFontSize.x * 1 , this->TexFontSize.y * 1, this->TexFontSize.x * 2 , this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("C", Box2D(this->TexFontSize.x * 2 , this->TexFontSize.y * 1, this->TexFontSize.x * 3 , this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("D", Box2D(this->TexFontSize.x * 3 , this->TexFontSize.y * 1, this->TexFontSize.x * 4 , this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("E", Box2D(this->TexFontSize.x * 4 , this->TexFontSize.y * 1, this->TexFontSize.x * 5 , this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("F", Box2D(this->TexFontSize.x * 5 , this->TexFontSize.y * 1, this->TexFontSize.x * 6 , this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("G", Box2D(this->TexFontSize.x * 6 , this->TexFontSize.y * 1, this->TexFontSize.x * 7 , this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("H", Box2D(this->TexFontSize.x * 7 , this->TexFontSize.y * 1, this->TexFontSize.x * 8 , this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("I", Box2D(this->TexFontSize.x * 8 , this->TexFontSize.y * 1, this->TexFontSize.x * 9 , this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("J", Box2D(this->TexFontSize.x * 9 , this->TexFontSize.y * 1, this->TexFontSize.x * 10, this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("K", Box2D(this->TexFontSize.x * 10, this->TexFontSize.y * 1, this->TexFontSize.x * 11, this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("L", Box2D(this->TexFontSize.x * 11, this->TexFontSize.y * 1, this->TexFontSize.x * 12, this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("M", Box2D(this->TexFontSize.x * 12, this->TexFontSize.y * 1, this->TexFontSize.x * 13, this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("N", Box2D(this->TexFontSize.x * 13, this->TexFontSize.y * 1, this->TexFontSize.x * 14, this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("O", Box2D(this->TexFontSize.x * 14, this->TexFontSize.y * 1, this->TexFontSize.x * 15, this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("P", Box2D(this->TexFontSize.x * 15, this->TexFontSize.y * 1, this->TexFontSize.x * 16, this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("Q", Box2D(this->TexFontSize.x * 16, this->TexFontSize.y * 1, this->TexFontSize.x * 17, this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("R", Box2D(this->TexFontSize.x * 17, this->TexFontSize.y * 1, this->TexFontSize.x * 18, this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("S", Box2D(this->TexFontSize.x * 18, this->TexFontSize.y * 1, this->TexFontSize.x * 19, this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("T", Box2D(this->TexFontSize.x * 19, this->TexFontSize.y * 1, this->TexFontSize.x * 20, this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("U", Box2D(this->TexFontSize.x * 20, this->TexFontSize.y * 1, this->TexFontSize.x * 21, this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("V", Box2D(this->TexFontSize.x * 21, this->TexFontSize.y * 1, this->TexFontSize.x * 22, this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("W", Box2D(this->TexFontSize.x * 22, this->TexFontSize.y * 1, this->TexFontSize.x * 23, this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("X", Box2D(this->TexFontSize.x * 23, this->TexFontSize.y * 1, this->TexFontSize.x * 24, this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("Y", Box2D(this->TexFontSize.x * 24, this->TexFontSize.y * 1, this->TexFontSize.x * 25, this->TexFontSize.y * 2)));
	this->func.insert(std::make_pair("Z", Box2D(this->TexFontSize.x * 25, this->TexFontSize.y * 1, this->TexFontSize.x * 26, this->TexFontSize.y * 2)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 2, this->TexFontSize.x * 1, this->TexFontSize.y * 3)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 2, this->TexFontSize.x * 2, this->TexFontSize.y * 3)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 2, this->TexFontSize.x * 3, this->TexFontSize.y * 3)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 2, this->TexFontSize.x * 4, this->TexFontSize.y * 3)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 2, this->TexFontSize.x * 5, this->TexFontSize.y * 3)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 3, this->TexFontSize.x * 1, this->TexFontSize.y * 4)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 3, this->TexFontSize.x * 2, this->TexFontSize.y * 4)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 3, this->TexFontSize.x * 3, this->TexFontSize.y * 4)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 3, this->TexFontSize.x * 4, this->TexFontSize.y * 4)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 3, this->TexFontSize.x * 5, this->TexFontSize.y * 4)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 4, this->TexFontSize.x * 1, this->TexFontSize.y * 5)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 4, this->TexFontSize.x * 2, this->TexFontSize.y * 5)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 4, this->TexFontSize.x * 3, this->TexFontSize.y * 5)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 4, this->TexFontSize.x * 4, this->TexFontSize.y * 5)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 4, this->TexFontSize.x * 5, this->TexFontSize.y * 5)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 5, this->TexFontSize.x * 1, this->TexFontSize.y * 6)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 5, this->TexFontSize.x * 2, this->TexFontSize.y * 6)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 5, this->TexFontSize.x * 3, this->TexFontSize.y * 6)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 5, this->TexFontSize.x * 4, this->TexFontSize.y * 6)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 5, this->TexFontSize.x * 5, this->TexFontSize.y * 6)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 6, this->TexFontSize.x * 1, this->TexFontSize.y * 7)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 6, this->TexFontSize.x * 2, this->TexFontSize.y * 7)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 6, this->TexFontSize.x * 3, this->TexFontSize.y * 7)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 6, this->TexFontSize.x * 4, this->TexFontSize.y * 7)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 6, this->TexFontSize.x * 5, this->TexFontSize.y * 7)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 7, this->TexFontSize.x * 1, this->TexFontSize.y * 8)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 7, this->TexFontSize.x * 2, this->TexFontSize.y * 8)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 7, this->TexFontSize.x * 3, this->TexFontSize.y * 8)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 7, this->TexFontSize.x * 4, this->TexFontSize.y * 8)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 7, this->TexFontSize.x * 5, this->TexFontSize.y * 8)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 8, this->TexFontSize.x * 1, this->TexFontSize.y * 9)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 8, this->TexFontSize.x * 2, this->TexFontSize.y * 9)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 8, this->TexFontSize.x * 3, this->TexFontSize.y * 9)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 8, this->TexFontSize.x * 4, this->TexFontSize.y * 9)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 8, this->TexFontSize.x * 5, this->TexFontSize.y * 9)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 9, this->TexFontSize.x * 1, this->TexFontSize.y * 10)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 9, this->TexFontSize.x * 2, this->TexFontSize.y * 10)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 9, this->TexFontSize.x * 3, this->TexFontSize.y * 10)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 10, this->TexFontSize.x * 1, this->TexFontSize.y * 11)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 10, this->TexFontSize.x * 2, this->TexFontSize.y * 11)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 10, this->TexFontSize.x * 3, this->TexFontSize.y * 11)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 10, this->TexFontSize.x * 4, this->TexFontSize.y * 11)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 10, this->TexFontSize.x * 5, this->TexFontSize.y * 11)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 11, this->TexFontSize.x * 1, this->TexFontSize.y * 12)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 11, this->TexFontSize.x * 2, this->TexFontSize.y * 12)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 11, this->TexFontSize.x * 3, this->TexFontSize.y * 12)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 11, this->TexFontSize.x * 4, this->TexFontSize.y * 12)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 11, this->TexFontSize.x * 5, this->TexFontSize.y * 12)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 12, this->TexFontSize.x * 1, this->TexFontSize.y * 13)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 12, this->TexFontSize.x * 2, this->TexFontSize.y * 13)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 12, this->TexFontSize.x * 3, this->TexFontSize.y * 13)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 12, this->TexFontSize.x * 4, this->TexFontSize.y * 13)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 12, this->TexFontSize.x * 5, this->TexFontSize.y * 13)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 13, this->TexFontSize.x * 1, this->TexFontSize.y * 14)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 13, this->TexFontSize.x * 2, this->TexFontSize.y * 14)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 13, this->TexFontSize.x * 3, this->TexFontSize.y * 14)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 13, this->TexFontSize.x * 4, this->TexFontSize.y * 14)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 13, this->TexFontSize.x * 5, this->TexFontSize.y * 14)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 14, this->TexFontSize.x * 1, this->TexFontSize.y * 15)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 14, this->TexFontSize.x * 2, this->TexFontSize.y * 15)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 14, this->TexFontSize.x * 3, this->TexFontSize.y * 15)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 14, this->TexFontSize.x * 4, this->TexFontSize.y * 15)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 14, this->TexFontSize.x * 5, this->TexFontSize.y * 15)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 15, this->TexFontSize.x * 1, this->TexFontSize.y * 16)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 15, this->TexFontSize.x * 2, this->TexFontSize.y * 16)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 15, this->TexFontSize.x * 3, this->TexFontSize.y * 16)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 15, this->TexFontSize.x * 4, this->TexFontSize.y * 16)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 15, this->TexFontSize.x * 5, this->TexFontSize.y * 16)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 16, this->TexFontSize.x * 1, this->TexFontSize.y * 17)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 16, this->TexFontSize.x * 2, this->TexFontSize.y * 17)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 16, this->TexFontSize.x * 3, this->TexFontSize.y * 17)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 16, this->TexFontSize.x * 4, this->TexFontSize.y * 17)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 16, this->TexFontSize.x * 5, this->TexFontSize.y * 17)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 17, this->TexFontSize.x * 1, this->TexFontSize.y * 18)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 17, this->TexFontSize.x * 2, this->TexFontSize.y * 18)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 17, this->TexFontSize.x * 3, this->TexFontSize.y * 18)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 17, this->TexFontSize.x * 4, this->TexFontSize.y * 18)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 17, this->TexFontSize.x * 5, this->TexFontSize.y * 18)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 18, this->TexFontSize.x * 1, this->TexFontSize.y * 19)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 18, this->TexFontSize.x * 2, this->TexFontSize.y * 19)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 18, this->TexFontSize.x * 3, this->TexFontSize.y * 19)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 18, this->TexFontSize.x * 4, this->TexFontSize.y * 19)));

	this->func.insert(std::make_pair("�A", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 19, this->TexFontSize.x * 1, this->TexFontSize.y * 20)));
	this->func.insert(std::make_pair("�C", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 19, this->TexFontSize.x * 2, this->TexFontSize.y * 20)));
	this->func.insert(std::make_pair("�E", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 19, this->TexFontSize.x * 3, this->TexFontSize.y * 20)));
	this->func.insert(std::make_pair("�G", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 19, this->TexFontSize.x * 4, this->TexFontSize.y * 20)));
	this->func.insert(std::make_pair("�I", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 19, this->TexFontSize.x * 5, this->TexFontSize.y * 20)));

	this->func.insert(std::make_pair("�J", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 20, this->TexFontSize.x * 1, this->TexFontSize.y * 21)));
	this->func.insert(std::make_pair("�L", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 20, this->TexFontSize.x * 2, this->TexFontSize.y * 21)));
	this->func.insert(std::make_pair("�N", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 20, this->TexFontSize.x * 3, this->TexFontSize.y * 21)));
	this->func.insert(std::make_pair("�P", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 20, this->TexFontSize.x * 4, this->TexFontSize.y * 21)));
	this->func.insert(std::make_pair("�R", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 20, this->TexFontSize.x * 5, this->TexFontSize.y * 21)));

	this->func.insert(std::make_pair("�T", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 21, this->TexFontSize.x * 1, this->TexFontSize.y * 22)));
	this->func.insert(std::make_pair("�V", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 21, this->TexFontSize.x * 2, this->TexFontSize.y * 22)));
	this->func.insert(std::make_pair("�X", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 21, this->TexFontSize.x * 3, this->TexFontSize.y * 22)));
	this->func.insert(std::make_pair("�Z", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 21, this->TexFontSize.x * 4, this->TexFontSize.y * 22)));
	this->func.insert(std::make_pair("�\", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 21, this->TexFontSize.x * 5, this->TexFontSize.y * 22)));

	this->func.insert(std::make_pair("�^", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 22, this->TexFontSize.x * 1, this->TexFontSize.y * 23)));
	this->func.insert(std::make_pair("�`", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 22, this->TexFontSize.x * 2, this->TexFontSize.y * 23)));
	this->func.insert(std::make_pair("�c", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 22, this->TexFontSize.x * 3, this->TexFontSize.y * 23)));
	this->func.insert(std::make_pair("�e", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 22, this->TexFontSize.x * 4, this->TexFontSize.y * 23)));
	this->func.insert(std::make_pair("�g", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 22, this->TexFontSize.x * 5, this->TexFontSize.y * 23)));

	this->func.insert(std::make_pair("�i", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 23, this->TexFontSize.x * 1, this->TexFontSize.y * 24)));
	this->func.insert(std::make_pair("�j", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 23, this->TexFontSize.x * 2, this->TexFontSize.y * 24)));
	this->func.insert(std::make_pair("�k", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 23, this->TexFontSize.x * 3, this->TexFontSize.y * 24)));
	this->func.insert(std::make_pair("�l", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 23, this->TexFontSize.x * 4, this->TexFontSize.y * 24)));
	this->func.insert(std::make_pair("�m", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 23, this->TexFontSize.x * 5, this->TexFontSize.y * 24)));

	this->func.insert(std::make_pair("�n", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 24, this->TexFontSize.x * 1, this->TexFontSize.y * 25)));
	this->func.insert(std::make_pair("�q", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 24, this->TexFontSize.x * 2, this->TexFontSize.y * 25)));
	this->func.insert(std::make_pair("�t", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 24, this->TexFontSize.x * 3, this->TexFontSize.y * 25)));
	this->func.insert(std::make_pair("�w", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 24, this->TexFontSize.x * 4, this->TexFontSize.y * 25)));
	this->func.insert(std::make_pair("�z", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 24, this->TexFontSize.x * 5, this->TexFontSize.y * 25)));

	this->func.insert(std::make_pair("�}", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 25, this->TexFontSize.x * 1, this->TexFontSize.y * 26)));
	this->func.insert(std::make_pair("�~", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 25, this->TexFontSize.x * 2, this->TexFontSize.y * 26)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 25, this->TexFontSize.x * 3, this->TexFontSize.y * 26)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 25, this->TexFontSize.x * 4, this->TexFontSize.y * 26)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 25, this->TexFontSize.x * 5, this->TexFontSize.y * 26)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 26, this->TexFontSize.x * 1, this->TexFontSize.y * 27)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 26, this->TexFontSize.x * 2, this->TexFontSize.y * 27)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 26, this->TexFontSize.x * 3, this->TexFontSize.y * 27)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 27, this->TexFontSize.x * 1, this->TexFontSize.y * 28)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 27, this->TexFontSize.x * 2, this->TexFontSize.y * 28)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 27, this->TexFontSize.x * 3, this->TexFontSize.y * 28)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 27, this->TexFontSize.x * 4, this->TexFontSize.y * 28)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 27, this->TexFontSize.x * 5, this->TexFontSize.y * 28)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 28, this->TexFontSize.x * 1, this->TexFontSize.y * 29)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 28, this->TexFontSize.x * 2, this->TexFontSize.y * 29)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 28, this->TexFontSize.x * 3, this->TexFontSize.y * 29)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 28, this->TexFontSize.x * 4, this->TexFontSize.y * 29)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 28, this->TexFontSize.x * 5, this->TexFontSize.y * 29)));

	this->func.insert(std::make_pair("�K", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 29, this->TexFontSize.x * 1, this->TexFontSize.y * 30)));
	this->func.insert(std::make_pair("�M", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 29, this->TexFontSize.x * 2, this->TexFontSize.y * 30)));
	this->func.insert(std::make_pair("�O", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 29, this->TexFontSize.x * 3, this->TexFontSize.y * 30)));
	this->func.insert(std::make_pair("�Q", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 29, this->TexFontSize.x * 4, this->TexFontSize.y * 30)));
	this->func.insert(std::make_pair("�S", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 29, this->TexFontSize.x * 5, this->TexFontSize.y * 30)));

	this->func.insert(std::make_pair("�U", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 30, this->TexFontSize.x * 1, this->TexFontSize.y * 31)));
	this->func.insert(std::make_pair("�W", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 30, this->TexFontSize.x * 2, this->TexFontSize.y * 31)));
	this->func.insert(std::make_pair("�Y", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 30, this->TexFontSize.x * 3, this->TexFontSize.y * 31)));
	this->func.insert(std::make_pair("�[", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 30, this->TexFontSize.x * 4, this->TexFontSize.y * 31)));
	this->func.insert(std::make_pair("�]", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 30, this->TexFontSize.x * 5, this->TexFontSize.y * 31)));

	this->func.insert(std::make_pair("�_", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 31, this->TexFontSize.x * 1, this->TexFontSize.y * 32)));
	this->func.insert(std::make_pair("�a", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 31, this->TexFontSize.x * 2, this->TexFontSize.y * 32)));
	this->func.insert(std::make_pair("�d", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 31, this->TexFontSize.x * 3, this->TexFontSize.y * 32)));
	this->func.insert(std::make_pair("�f", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 31, this->TexFontSize.x * 4, this->TexFontSize.y * 32)));
	this->func.insert(std::make_pair("�h", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 31, this->TexFontSize.x * 5, this->TexFontSize.y * 32)));

	this->func.insert(std::make_pair("�o", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 32, this->TexFontSize.x * 1, this->TexFontSize.y * 33)));
	this->func.insert(std::make_pair("�r", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 32, this->TexFontSize.x * 2, this->TexFontSize.y * 33)));
	this->func.insert(std::make_pair("�u", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 32, this->TexFontSize.x * 3, this->TexFontSize.y * 33)));
	this->func.insert(std::make_pair("�x", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 32, this->TexFontSize.x * 4, this->TexFontSize.y * 33)));
	this->func.insert(std::make_pair("�{", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 32, this->TexFontSize.x * 5, this->TexFontSize.y * 33)));

	this->func.insert(std::make_pair("�p", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 33, this->TexFontSize.x * 1, this->TexFontSize.y * 34)));
	this->func.insert(std::make_pair("�s", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 33, this->TexFontSize.x * 2, this->TexFontSize.y * 34)));
	this->func.insert(std::make_pair("�v", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 33, this->TexFontSize.x * 3, this->TexFontSize.y * 34)));
	this->func.insert(std::make_pair("�y", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 33, this->TexFontSize.x * 4, this->TexFontSize.y * 34)));
	this->func.insert(std::make_pair("�|", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 33, this->TexFontSize.x * 5, this->TexFontSize.y * 34)));

	this->func.insert(std::make_pair("�@", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 34, this->TexFontSize.x * 1, this->TexFontSize.y * 35)));
	this->func.insert(std::make_pair("�B", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 34, this->TexFontSize.x * 2, this->TexFontSize.y * 35)));
	this->func.insert(std::make_pair("�D", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 34, this->TexFontSize.x * 3, this->TexFontSize.y * 35)));
	this->func.insert(std::make_pair("�F", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 34, this->TexFontSize.x * 4, this->TexFontSize.y * 35)));
	this->func.insert(std::make_pair("�H", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 34, this->TexFontSize.x * 5, this->TexFontSize.y * 35)));

	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 35, this->TexFontSize.x * 1, this->TexFontSize.y * 36)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 35, this->TexFontSize.x * 2, this->TexFontSize.y * 36)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 35, this->TexFontSize.x * 3, this->TexFontSize.y * 36)));
	this->func.insert(std::make_pair("�b", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 35, this->TexFontSize.x * 4, this->TexFontSize.y * 36)));
	this->func.insert(std::make_pair("��", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 35, this->TexFontSize.x * 5, this->TexFontSize.y * 36)));
}