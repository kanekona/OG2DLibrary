#include "TextureFont.h"
#include "OG\OGsystem.h"
Font::Font()
	:TexFontSize(Vec2(70.f,71.f)),TexNumberSize(Vec2(39.8f,71.f)),TexHalfFontSize(Vec2(35,71))
{
	this->fontTex = nullptr;
	this->SetTexture("font1");
	this->CreateCharacter();
}
Font::~Font()
{
}
void Font::Draw(const std::string& text,const Vec2& pos,const int fontSize,const Color& color)
{
	//保持データを初期化
	this->texSize = 0;
	this->drawText = text;
	//文字列がなくなるまでループ
	while (!this->drawText.empty())
	{
		//先頭文字が何バイトなのか調べる
		switch (OG::mbclen(this->drawText.substr(0, 1).c_str()))
		{
		case 2: //2byte
			//描画位置指定
			this->draw = Box2D(pos.x + (fontSize * this->texSize), pos.y,(float)fontSize, (float)fontSize);
			//フォントデータを取得
			this->src = this->CharacterCheck(this->drawText.substr(0, 2));
			if (this->src)
			{
				this->draw.OffsetSize();
				this->fontTex->Draw(this->draw, *this->src, color);
			}
			//描画を終えた文字列を消す
			this->drawText.erase(0, 2);
			this->texSize += 1.f;
			break;
		case 1: //1byte
			//描画位置指定
			this->draw = Box2D(pos.x + (fontSize * this->texSize), pos.y, (float)fontSize / 2, (float)fontSize);
			//フォントデータを取得
			this->src = this->CharacterCheck(this->drawText.substr(0, 1));
			if (this->src)
			{
				this->draw.OffsetSize();
				this->fontTex->Draw(this->draw, *this->src, color);
			}
			//描画を終えた文字列を消す
			this->drawText.erase(0, 1);
			this->texSize += 0.5f;
			break;
		default: //例外エラー(spaceとして処理)
			this->texSize += 0.5f;
			break;
		}
	}
}
Box2D* Font::CharacterCheck(const std::string& c)
{
	if (this->func.find(c) != this->func.end())
	{
		//std::mapの検索でhitしたものを返す
		return &this->func[c];
	}
	//見つからなかった場合nullptr
	//※現在仮、読み込みに失敗したら?を返すようにする
	return nullptr;
}
void Font::SetTexture(const std::string& path)
{
	this->fontTex = rm->GetTextureData(path);
}
void Font::CreateCharacter()
{
	//フォントデータ生成
	{
		this->func.insert(std::make_pair("ａ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 0, this->TexFontSize.x * 1, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｂ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 0, this->TexFontSize.x * 2, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｃ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 0, this->TexFontSize.x * 3, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｄ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 0, this->TexFontSize.x * 4, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｅ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 0, this->TexFontSize.x * 5, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｆ", Box2D(this->TexFontSize.x * 5, this->TexFontSize.y * 0, this->TexFontSize.x * 6, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｇ", Box2D(this->TexFontSize.x * 6, this->TexFontSize.y * 0, this->TexFontSize.x * 7, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｈ", Box2D(this->TexFontSize.x * 7, this->TexFontSize.y * 0, this->TexFontSize.x * 8, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｉ", Box2D(this->TexFontSize.x * 8, this->TexFontSize.y * 0, this->TexFontSize.x * 9, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｊ", Box2D(this->TexFontSize.x * 9, this->TexFontSize.y * 0, this->TexFontSize.x * 10, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｋ", Box2D(this->TexFontSize.x * 10, this->TexFontSize.y * 0, this->TexFontSize.x * 11, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｌ", Box2D(this->TexFontSize.x * 11, this->TexFontSize.y * 0, this->TexFontSize.x * 12, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｍ", Box2D(this->TexFontSize.x * 12, this->TexFontSize.y * 0, this->TexFontSize.x * 13, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｎ", Box2D(this->TexFontSize.x * 13, this->TexFontSize.y * 0, this->TexFontSize.x * 14, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｏ", Box2D(this->TexFontSize.x * 14, this->TexFontSize.y * 0, this->TexFontSize.x * 15, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｐ", Box2D(this->TexFontSize.x * 15, this->TexFontSize.y * 0, this->TexFontSize.x * 16, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｑ", Box2D(this->TexFontSize.x * 16, this->TexFontSize.y * 0, this->TexFontSize.x * 17, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｒ", Box2D(this->TexFontSize.x * 17, this->TexFontSize.y * 0, this->TexFontSize.x * 18, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｓ", Box2D(this->TexFontSize.x * 18, this->TexFontSize.y * 0, this->TexFontSize.x * 19, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｔ", Box2D(this->TexFontSize.x * 19, this->TexFontSize.y * 0, this->TexFontSize.x * 20, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｕ", Box2D(this->TexFontSize.x * 20, this->TexFontSize.y * 0, this->TexFontSize.x * 21, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｖ", Box2D(this->TexFontSize.x * 21, this->TexFontSize.y * 0, this->TexFontSize.x * 22, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｗ", Box2D(this->TexFontSize.x * 22, this->TexFontSize.y * 0, this->TexFontSize.x * 23, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｘ", Box2D(this->TexFontSize.x * 23, this->TexFontSize.y * 0, this->TexFontSize.x * 24, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｙ", Box2D(this->TexFontSize.x * 24, this->TexFontSize.y * 0, this->TexFontSize.x * 25, this->TexFontSize.y * 1)));
		this->func.insert(std::make_pair("ｚ", Box2D(this->TexFontSize.x * 25, this->TexFontSize.y * 0, this->TexFontSize.x * 26, this->TexFontSize.y * 1)));

		this->func.insert(std::make_pair("Ａ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 1, this->TexFontSize.x * 1, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｂ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 1, this->TexFontSize.x * 2, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｃ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 1, this->TexFontSize.x * 3, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｄ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 1, this->TexFontSize.x * 4, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｅ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 1, this->TexFontSize.x * 5, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｆ", Box2D(this->TexFontSize.x * 5, this->TexFontSize.y * 1, this->TexFontSize.x * 6, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｇ", Box2D(this->TexFontSize.x * 6, this->TexFontSize.y * 1, this->TexFontSize.x * 7, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｈ", Box2D(this->TexFontSize.x * 7, this->TexFontSize.y * 1, this->TexFontSize.x * 8, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｉ", Box2D(this->TexFontSize.x * 8, this->TexFontSize.y * 1, this->TexFontSize.x * 9, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｊ", Box2D(this->TexFontSize.x * 9, this->TexFontSize.y * 1, this->TexFontSize.x * 10, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｋ", Box2D(this->TexFontSize.x * 10, this->TexFontSize.y * 1, this->TexFontSize.x * 11, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｌ", Box2D(this->TexFontSize.x * 11, this->TexFontSize.y * 1, this->TexFontSize.x * 12, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｍ", Box2D(this->TexFontSize.x * 12, this->TexFontSize.y * 1, this->TexFontSize.x * 13, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｎ", Box2D(this->TexFontSize.x * 13, this->TexFontSize.y * 1, this->TexFontSize.x * 14, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｏ", Box2D(this->TexFontSize.x * 14, this->TexFontSize.y * 1, this->TexFontSize.x * 15, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｐ", Box2D(this->TexFontSize.x * 15, this->TexFontSize.y * 1, this->TexFontSize.x * 16, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｑ", Box2D(this->TexFontSize.x * 16, this->TexFontSize.y * 1, this->TexFontSize.x * 17, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｒ", Box2D(this->TexFontSize.x * 17, this->TexFontSize.y * 1, this->TexFontSize.x * 18, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｓ", Box2D(this->TexFontSize.x * 18, this->TexFontSize.y * 1, this->TexFontSize.x * 19, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｔ", Box2D(this->TexFontSize.x * 19, this->TexFontSize.y * 1, this->TexFontSize.x * 20, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｕ", Box2D(this->TexFontSize.x * 20, this->TexFontSize.y * 1, this->TexFontSize.x * 21, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｖ", Box2D(this->TexFontSize.x * 21, this->TexFontSize.y * 1, this->TexFontSize.x * 22, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｗ", Box2D(this->TexFontSize.x * 22, this->TexFontSize.y * 1, this->TexFontSize.x * 23, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｘ", Box2D(this->TexFontSize.x * 23, this->TexFontSize.y * 1, this->TexFontSize.x * 24, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｙ", Box2D(this->TexFontSize.x * 24, this->TexFontSize.y * 1, this->TexFontSize.x * 25, this->TexFontSize.y * 2)));
		this->func.insert(std::make_pair("Ｚ", Box2D(this->TexFontSize.x * 25, this->TexFontSize.y * 1, this->TexFontSize.x * 26, this->TexFontSize.y * 2)));

		this->func.insert(std::make_pair("あ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 2, this->TexFontSize.x * 1, this->TexFontSize.y * 3)));
		this->func.insert(std::make_pair("い", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 2, this->TexFontSize.x * 2, this->TexFontSize.y * 3)));
		this->func.insert(std::make_pair("う", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 2, this->TexFontSize.x * 3, this->TexFontSize.y * 3)));
		this->func.insert(std::make_pair("え", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 2, this->TexFontSize.x * 4, this->TexFontSize.y * 3)));
		this->func.insert(std::make_pair("お", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 2, this->TexFontSize.x * 5, this->TexFontSize.y * 3)));

		this->func.insert(std::make_pair("か", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 3, this->TexFontSize.x * 1, this->TexFontSize.y * 4)));
		this->func.insert(std::make_pair("き", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 3, this->TexFontSize.x * 2, this->TexFontSize.y * 4)));
		this->func.insert(std::make_pair("く", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 3, this->TexFontSize.x * 3, this->TexFontSize.y * 4)));
		this->func.insert(std::make_pair("け", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 3, this->TexFontSize.x * 4, this->TexFontSize.y * 4)));
		this->func.insert(std::make_pair("こ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 3, this->TexFontSize.x * 5, this->TexFontSize.y * 4)));

		this->func.insert(std::make_pair("さ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 4, this->TexFontSize.x * 1, this->TexFontSize.y * 5)));
		this->func.insert(std::make_pair("し", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 4, this->TexFontSize.x * 2, this->TexFontSize.y * 5)));
		this->func.insert(std::make_pair("す", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 4, this->TexFontSize.x * 3, this->TexFontSize.y * 5)));
		this->func.insert(std::make_pair("せ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 4, this->TexFontSize.x * 4, this->TexFontSize.y * 5)));
		this->func.insert(std::make_pair("そ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 4, this->TexFontSize.x * 5, this->TexFontSize.y * 5)));

		this->func.insert(std::make_pair("た", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 5, this->TexFontSize.x * 1, this->TexFontSize.y * 6)));
		this->func.insert(std::make_pair("ち", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 5, this->TexFontSize.x * 2, this->TexFontSize.y * 6)));
		this->func.insert(std::make_pair("つ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 5, this->TexFontSize.x * 3, this->TexFontSize.y * 6)));
		this->func.insert(std::make_pair("て", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 5, this->TexFontSize.x * 4, this->TexFontSize.y * 6)));
		this->func.insert(std::make_pair("と", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 5, this->TexFontSize.x * 5, this->TexFontSize.y * 6)));

		this->func.insert(std::make_pair("な", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 6, this->TexFontSize.x * 1, this->TexFontSize.y * 7)));
		this->func.insert(std::make_pair("に", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 6, this->TexFontSize.x * 2, this->TexFontSize.y * 7)));
		this->func.insert(std::make_pair("ぬ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 6, this->TexFontSize.x * 3, this->TexFontSize.y * 7)));
		this->func.insert(std::make_pair("ね", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 6, this->TexFontSize.x * 4, this->TexFontSize.y * 7)));
		this->func.insert(std::make_pair("の", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 6, this->TexFontSize.x * 5, this->TexFontSize.y * 7)));

		this->func.insert(std::make_pair("は", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 7, this->TexFontSize.x * 1, this->TexFontSize.y * 8)));
		this->func.insert(std::make_pair("ひ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 7, this->TexFontSize.x * 2, this->TexFontSize.y * 8)));
		this->func.insert(std::make_pair("ふ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 7, this->TexFontSize.x * 3, this->TexFontSize.y * 8)));
		this->func.insert(std::make_pair("へ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 7, this->TexFontSize.x * 4, this->TexFontSize.y * 8)));
		this->func.insert(std::make_pair("ほ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 7, this->TexFontSize.x * 5, this->TexFontSize.y * 8)));

		this->func.insert(std::make_pair("ま", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 8, this->TexFontSize.x * 1, this->TexFontSize.y * 9)));
		this->func.insert(std::make_pair("み", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 8, this->TexFontSize.x * 2, this->TexFontSize.y * 9)));
		this->func.insert(std::make_pair("む", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 8, this->TexFontSize.x * 3, this->TexFontSize.y * 9)));
		this->func.insert(std::make_pair("め", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 8, this->TexFontSize.x * 4, this->TexFontSize.y * 9)));
		this->func.insert(std::make_pair("も", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 8, this->TexFontSize.x * 5, this->TexFontSize.y * 9)));

		this->func.insert(std::make_pair("や", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 9, this->TexFontSize.x * 1, this->TexFontSize.y * 10)));
		this->func.insert(std::make_pair("ゆ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 9, this->TexFontSize.x * 2, this->TexFontSize.y * 10)));
		this->func.insert(std::make_pair("よ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 9, this->TexFontSize.x * 3, this->TexFontSize.y * 10)));

		this->func.insert(std::make_pair("ら", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 10, this->TexFontSize.x * 1, this->TexFontSize.y * 11)));
		this->func.insert(std::make_pair("り", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 10, this->TexFontSize.x * 2, this->TexFontSize.y * 11)));
		this->func.insert(std::make_pair("る", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 10, this->TexFontSize.x * 3, this->TexFontSize.y * 11)));
		this->func.insert(std::make_pair("れ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 10, this->TexFontSize.x * 4, this->TexFontSize.y * 11)));
		this->func.insert(std::make_pair("ろ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 10, this->TexFontSize.x * 5, this->TexFontSize.y * 11)));

		this->func.insert(std::make_pair("わ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 11, this->TexFontSize.x * 1, this->TexFontSize.y * 12)));
		this->func.insert(std::make_pair("ゐ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 11, this->TexFontSize.x * 2, this->TexFontSize.y * 12)));
		this->func.insert(std::make_pair("ゑ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 11, this->TexFontSize.x * 3, this->TexFontSize.y * 12)));
		this->func.insert(std::make_pair("を", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 11, this->TexFontSize.x * 4, this->TexFontSize.y * 12)));
		this->func.insert(std::make_pair("ん", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 11, this->TexFontSize.x * 5, this->TexFontSize.y * 12)));

		this->func.insert(std::make_pair("が", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 12, this->TexFontSize.x * 1, this->TexFontSize.y * 13)));
		this->func.insert(std::make_pair("ぎ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 12, this->TexFontSize.x * 2, this->TexFontSize.y * 13)));
		this->func.insert(std::make_pair("ぐ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 12, this->TexFontSize.x * 3, this->TexFontSize.y * 13)));
		this->func.insert(std::make_pair("げ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 12, this->TexFontSize.x * 4, this->TexFontSize.y * 13)));
		this->func.insert(std::make_pair("ご", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 12, this->TexFontSize.x * 5, this->TexFontSize.y * 13)));

		this->func.insert(std::make_pair("ざ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 13, this->TexFontSize.x * 1, this->TexFontSize.y * 14)));
		this->func.insert(std::make_pair("じ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 13, this->TexFontSize.x * 2, this->TexFontSize.y * 14)));
		this->func.insert(std::make_pair("ず", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 13, this->TexFontSize.x * 3, this->TexFontSize.y * 14)));
		this->func.insert(std::make_pair("ぜ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 13, this->TexFontSize.x * 4, this->TexFontSize.y * 14)));
		this->func.insert(std::make_pair("ぞ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 13, this->TexFontSize.x * 5, this->TexFontSize.y * 14)));

		this->func.insert(std::make_pair("だ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 14, this->TexFontSize.x * 1, this->TexFontSize.y * 15)));
		this->func.insert(std::make_pair("ぢ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 14, this->TexFontSize.x * 2, this->TexFontSize.y * 15)));
		this->func.insert(std::make_pair("づ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 14, this->TexFontSize.x * 3, this->TexFontSize.y * 15)));
		this->func.insert(std::make_pair("で", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 14, this->TexFontSize.x * 4, this->TexFontSize.y * 15)));
		this->func.insert(std::make_pair("ど", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 14, this->TexFontSize.x * 5, this->TexFontSize.y * 15)));

		this->func.insert(std::make_pair("ば", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 15, this->TexFontSize.x * 1, this->TexFontSize.y * 16)));
		this->func.insert(std::make_pair("び", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 15, this->TexFontSize.x * 2, this->TexFontSize.y * 16)));
		this->func.insert(std::make_pair("ぶ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 15, this->TexFontSize.x * 3, this->TexFontSize.y * 16)));
		this->func.insert(std::make_pair("べ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 15, this->TexFontSize.x * 4, this->TexFontSize.y * 16)));
		this->func.insert(std::make_pair("ぼ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 15, this->TexFontSize.x * 5, this->TexFontSize.y * 16)));

		this->func.insert(std::make_pair("ぱ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 16, this->TexFontSize.x * 1, this->TexFontSize.y * 17)));
		this->func.insert(std::make_pair("ぴ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 16, this->TexFontSize.x * 2, this->TexFontSize.y * 17)));
		this->func.insert(std::make_pair("ぷ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 16, this->TexFontSize.x * 3, this->TexFontSize.y * 17)));
		this->func.insert(std::make_pair("ぺ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 16, this->TexFontSize.x * 4, this->TexFontSize.y * 17)));
		this->func.insert(std::make_pair("ぽ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 16, this->TexFontSize.x * 5, this->TexFontSize.y * 17)));

		this->func.insert(std::make_pair("ぁ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 17, this->TexFontSize.x * 1, this->TexFontSize.y * 18)));
		this->func.insert(std::make_pair("ぃ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 17, this->TexFontSize.x * 2, this->TexFontSize.y * 18)));
		this->func.insert(std::make_pair("ぅ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 17, this->TexFontSize.x * 3, this->TexFontSize.y * 18)));
		this->func.insert(std::make_pair("ぇ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 17, this->TexFontSize.x * 4, this->TexFontSize.y * 18)));
		this->func.insert(std::make_pair("ぉ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 17, this->TexFontSize.x * 5, this->TexFontSize.y * 18)));

		this->func.insert(std::make_pair("ゃ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 18, this->TexFontSize.x * 1, this->TexFontSize.y * 19)));
		this->func.insert(std::make_pair("ゅ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 18, this->TexFontSize.x * 2, this->TexFontSize.y * 19)));
		this->func.insert(std::make_pair("ょ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 18, this->TexFontSize.x * 3, this->TexFontSize.y * 19)));
		this->func.insert(std::make_pair("っ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 18, this->TexFontSize.x * 4, this->TexFontSize.y * 19)));

		this->func.insert(std::make_pair("ア", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 19, this->TexFontSize.x * 1, this->TexFontSize.y * 20)));
		this->func.insert(std::make_pair("イ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 19, this->TexFontSize.x * 2, this->TexFontSize.y * 20)));
		this->func.insert(std::make_pair("ウ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 19, this->TexFontSize.x * 3, this->TexFontSize.y * 20)));
		this->func.insert(std::make_pair("エ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 19, this->TexFontSize.x * 4, this->TexFontSize.y * 20)));
		this->func.insert(std::make_pair("オ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 19, this->TexFontSize.x * 5, this->TexFontSize.y * 20)));

		this->func.insert(std::make_pair("カ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 20, this->TexFontSize.x * 1, this->TexFontSize.y * 21)));
		this->func.insert(std::make_pair("キ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 20, this->TexFontSize.x * 2, this->TexFontSize.y * 21)));
		this->func.insert(std::make_pair("ク", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 20, this->TexFontSize.x * 3, this->TexFontSize.y * 21)));
		this->func.insert(std::make_pair("ケ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 20, this->TexFontSize.x * 4, this->TexFontSize.y * 21)));
		this->func.insert(std::make_pair("コ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 20, this->TexFontSize.x * 5, this->TexFontSize.y * 21)));

		this->func.insert(std::make_pair("サ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 21, this->TexFontSize.x * 1, this->TexFontSize.y * 22)));
		this->func.insert(std::make_pair("シ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 21, this->TexFontSize.x * 2, this->TexFontSize.y * 22)));
		this->func.insert(std::make_pair("ス", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 21, this->TexFontSize.x * 3, this->TexFontSize.y * 22)));
		this->func.insert(std::make_pair("セ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 21, this->TexFontSize.x * 4, this->TexFontSize.y * 22)));
		this->func.insert(std::make_pair("ソ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 21, this->TexFontSize.x * 5, this->TexFontSize.y * 22)));

		this->func.insert(std::make_pair("タ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 22, this->TexFontSize.x * 1, this->TexFontSize.y * 23)));
		this->func.insert(std::make_pair("チ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 22, this->TexFontSize.x * 2, this->TexFontSize.y * 23)));
		this->func.insert(std::make_pair("ツ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 22, this->TexFontSize.x * 3, this->TexFontSize.y * 23)));
		this->func.insert(std::make_pair("テ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 22, this->TexFontSize.x * 4, this->TexFontSize.y * 23)));
		this->func.insert(std::make_pair("ト", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 22, this->TexFontSize.x * 5, this->TexFontSize.y * 23)));

		this->func.insert(std::make_pair("ナ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 23, this->TexFontSize.x * 1, this->TexFontSize.y * 24)));
		this->func.insert(std::make_pair("ニ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 23, this->TexFontSize.x * 2, this->TexFontSize.y * 24)));
		this->func.insert(std::make_pair("ヌ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 23, this->TexFontSize.x * 3, this->TexFontSize.y * 24)));
		this->func.insert(std::make_pair("ネ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 23, this->TexFontSize.x * 4, this->TexFontSize.y * 24)));
		this->func.insert(std::make_pair("ノ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 23, this->TexFontSize.x * 5, this->TexFontSize.y * 24)));

		this->func.insert(std::make_pair("ハ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 24, this->TexFontSize.x * 1, this->TexFontSize.y * 25)));
		this->func.insert(std::make_pair("ヒ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 24, this->TexFontSize.x * 2, this->TexFontSize.y * 25)));
		this->func.insert(std::make_pair("フ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 24, this->TexFontSize.x * 3, this->TexFontSize.y * 25)));
		this->func.insert(std::make_pair("ヘ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 24, this->TexFontSize.x * 4, this->TexFontSize.y * 25)));
		this->func.insert(std::make_pair("ホ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 24, this->TexFontSize.x * 5, this->TexFontSize.y * 25)));

		this->func.insert(std::make_pair("マ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 25, this->TexFontSize.x * 1, this->TexFontSize.y * 26)));
		this->func.insert(std::make_pair("ミ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 25, this->TexFontSize.x * 2, this->TexFontSize.y * 26)));
		this->func.insert(std::make_pair("ム", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 25, this->TexFontSize.x * 3, this->TexFontSize.y * 26)));
		this->func.insert(std::make_pair("メ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 25, this->TexFontSize.x * 4, this->TexFontSize.y * 26)));
		this->func.insert(std::make_pair("モ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 25, this->TexFontSize.x * 5, this->TexFontSize.y * 26)));

		this->func.insert(std::make_pair("ヤ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 26, this->TexFontSize.x * 1, this->TexFontSize.y * 27)));
		this->func.insert(std::make_pair("ユ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 26, this->TexFontSize.x * 2, this->TexFontSize.y * 27)));
		this->func.insert(std::make_pair("ヨ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 26, this->TexFontSize.x * 3, this->TexFontSize.y * 27)));

		this->func.insert(std::make_pair("ラ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 27, this->TexFontSize.x * 1, this->TexFontSize.y * 28)));
		this->func.insert(std::make_pair("リ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 27, this->TexFontSize.x * 2, this->TexFontSize.y * 28)));
		this->func.insert(std::make_pair("ル", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 27, this->TexFontSize.x * 3, this->TexFontSize.y * 28)));
		this->func.insert(std::make_pair("レ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 27, this->TexFontSize.x * 4, this->TexFontSize.y * 28)));
		this->func.insert(std::make_pair("ロ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 27, this->TexFontSize.x * 5, this->TexFontSize.y * 28)));

		this->func.insert(std::make_pair("ワ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 28, this->TexFontSize.x * 1, this->TexFontSize.y * 29)));
		this->func.insert(std::make_pair("ヰ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 28, this->TexFontSize.x * 2, this->TexFontSize.y * 29)));
		this->func.insert(std::make_pair("ヱ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 28, this->TexFontSize.x * 3, this->TexFontSize.y * 29)));
		this->func.insert(std::make_pair("ヲ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 28, this->TexFontSize.x * 4, this->TexFontSize.y * 29)));
		this->func.insert(std::make_pair("ン", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 28, this->TexFontSize.x * 5, this->TexFontSize.y * 29)));

		this->func.insert(std::make_pair("ガ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 29, this->TexFontSize.x * 1, this->TexFontSize.y * 30)));
		this->func.insert(std::make_pair("ギ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 29, this->TexFontSize.x * 2, this->TexFontSize.y * 30)));
		this->func.insert(std::make_pair("グ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 29, this->TexFontSize.x * 3, this->TexFontSize.y * 30)));
		this->func.insert(std::make_pair("ゲ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 29, this->TexFontSize.x * 4, this->TexFontSize.y * 30)));
		this->func.insert(std::make_pair("ゴ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 29, this->TexFontSize.x * 5, this->TexFontSize.y * 30)));

		this->func.insert(std::make_pair("ザ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 30, this->TexFontSize.x * 1, this->TexFontSize.y * 31)));
		this->func.insert(std::make_pair("ジ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 30, this->TexFontSize.x * 2, this->TexFontSize.y * 31)));
		this->func.insert(std::make_pair("ズ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 30, this->TexFontSize.x * 3, this->TexFontSize.y * 31)));
		this->func.insert(std::make_pair("ゼ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 30, this->TexFontSize.x * 4, this->TexFontSize.y * 31)));
		this->func.insert(std::make_pair("ゾ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 30, this->TexFontSize.x * 5, this->TexFontSize.y * 31)));

		this->func.insert(std::make_pair("ダ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 31, this->TexFontSize.x * 1, this->TexFontSize.y * 32)));
		this->func.insert(std::make_pair("ヂ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 31, this->TexFontSize.x * 2, this->TexFontSize.y * 32)));
		this->func.insert(std::make_pair("ヅ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 31, this->TexFontSize.x * 3, this->TexFontSize.y * 32)));
		this->func.insert(std::make_pair("デ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 31, this->TexFontSize.x * 4, this->TexFontSize.y * 32)));
		this->func.insert(std::make_pair("ド", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 31, this->TexFontSize.x * 5, this->TexFontSize.y * 32)));

		this->func.insert(std::make_pair("バ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 32, this->TexFontSize.x * 1, this->TexFontSize.y * 33)));
		this->func.insert(std::make_pair("ビ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 32, this->TexFontSize.x * 2, this->TexFontSize.y * 33)));
		this->func.insert(std::make_pair("ブ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 32, this->TexFontSize.x * 3, this->TexFontSize.y * 33)));
		this->func.insert(std::make_pair("ベ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 32, this->TexFontSize.x * 4, this->TexFontSize.y * 33)));
		this->func.insert(std::make_pair("ボ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 32, this->TexFontSize.x * 5, this->TexFontSize.y * 33)));

		this->func.insert(std::make_pair("パ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 33, this->TexFontSize.x * 1, this->TexFontSize.y * 34)));
		this->func.insert(std::make_pair("ピ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 33, this->TexFontSize.x * 2, this->TexFontSize.y * 34)));
		this->func.insert(std::make_pair("プ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 33, this->TexFontSize.x * 3, this->TexFontSize.y * 34)));
		this->func.insert(std::make_pair("ペ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 33, this->TexFontSize.x * 4, this->TexFontSize.y * 34)));
		this->func.insert(std::make_pair("ポ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 33, this->TexFontSize.x * 5, this->TexFontSize.y * 34)));

		this->func.insert(std::make_pair("ァ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 34, this->TexFontSize.x * 1, this->TexFontSize.y * 35)));
		this->func.insert(std::make_pair("ィ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 34, this->TexFontSize.x * 2, this->TexFontSize.y * 35)));
		this->func.insert(std::make_pair("ゥ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 34, this->TexFontSize.x * 3, this->TexFontSize.y * 35)));
		this->func.insert(std::make_pair("ェ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 34, this->TexFontSize.x * 4, this->TexFontSize.y * 35)));
		this->func.insert(std::make_pair("ォ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 34, this->TexFontSize.x * 5, this->TexFontSize.y * 35)));

		this->func.insert(std::make_pair("ャ", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 35, this->TexFontSize.x * 1, this->TexFontSize.y * 36)));
		this->func.insert(std::make_pair("ュ", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 35, this->TexFontSize.x * 2, this->TexFontSize.y * 36)));
		this->func.insert(std::make_pair("ョ", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 35, this->TexFontSize.x * 3, this->TexFontSize.y * 36)));
		this->func.insert(std::make_pair("ッ", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 35, this->TexFontSize.x * 4, this->TexFontSize.y * 36)));
		this->func.insert(std::make_pair("ヴ", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 35, this->TexFontSize.x * 5, this->TexFontSize.y * 36)));

		this->func.insert(std::make_pair("1", Box2D(this->TexNumberSize.x * 0, this->TexNumberSize.y * 36, this->TexNumberSize.x * 1, this->TexNumberSize.y * 37)));
		this->func.insert(std::make_pair("2", Box2D(this->TexNumberSize.x * 1, this->TexNumberSize.y * 36, this->TexNumberSize.x * 2, this->TexNumberSize.y * 37)));
		this->func.insert(std::make_pair("3", Box2D(this->TexNumberSize.x * 2, this->TexNumberSize.y * 36, this->TexNumberSize.x * 3, this->TexNumberSize.y * 37)));
		this->func.insert(std::make_pair("4", Box2D(this->TexNumberSize.x * 3, this->TexNumberSize.y * 36, this->TexNumberSize.x * 4, this->TexNumberSize.y * 37)));
		this->func.insert(std::make_pair("5", Box2D(this->TexNumberSize.x * 4, this->TexNumberSize.y * 36, this->TexNumberSize.x * 5, this->TexNumberSize.y * 37)));
		this->func.insert(std::make_pair("6", Box2D(this->TexNumberSize.x * 5, this->TexNumberSize.y * 36, this->TexNumberSize.x * 6, this->TexNumberSize.y * 37)));
		this->func.insert(std::make_pair("7", Box2D(this->TexNumberSize.x * 6, this->TexNumberSize.y * 36, this->TexNumberSize.x * 7, this->TexNumberSize.y * 37)));
		this->func.insert(std::make_pair("8", Box2D(this->TexNumberSize.x * 7, this->TexNumberSize.y * 36, this->TexNumberSize.x * 8, this->TexNumberSize.y * 37)));
		this->func.insert(std::make_pair("9", Box2D(this->TexNumberSize.x * 8, this->TexNumberSize.y * 36, this->TexNumberSize.x * 9, this->TexNumberSize.y * 37)));
		this->func.insert(std::make_pair("0", Box2D(this->TexNumberSize.x * 9, this->TexNumberSize.y * 36, this->TexNumberSize.x * 10, this->TexNumberSize.y * 37)));

		this->func.insert(std::make_pair("１", Box2D(this->TexFontSize.x * 0, this->TexFontSize.y * 37, this->TexFontSize.x * 1, this->TexFontSize.y * 38)));
		this->func.insert(std::make_pair("２", Box2D(this->TexFontSize.x * 1, this->TexFontSize.y * 37, this->TexFontSize.x * 2, this->TexFontSize.y * 38)));
		this->func.insert(std::make_pair("３", Box2D(this->TexFontSize.x * 2, this->TexFontSize.y * 37, this->TexFontSize.x * 3, this->TexFontSize.y * 38)));
		this->func.insert(std::make_pair("４", Box2D(this->TexFontSize.x * 3, this->TexFontSize.y * 37, this->TexFontSize.x * 4, this->TexFontSize.y * 38)));
		this->func.insert(std::make_pair("５", Box2D(this->TexFontSize.x * 4, this->TexFontSize.y * 37, this->TexFontSize.x * 5, this->TexFontSize.y * 38)));
		this->func.insert(std::make_pair("６", Box2D(this->TexFontSize.x * 5, this->TexFontSize.y * 37, this->TexFontSize.x * 6, this->TexFontSize.y * 38)));
		this->func.insert(std::make_pair("７", Box2D(this->TexFontSize.x * 6, this->TexFontSize.y * 37, this->TexFontSize.x * 7, this->TexFontSize.y * 38)));
		this->func.insert(std::make_pair("８", Box2D(this->TexFontSize.x * 7, this->TexFontSize.y * 37, this->TexFontSize.x * 8, this->TexFontSize.y * 38)));
		this->func.insert(std::make_pair("９", Box2D(this->TexFontSize.x * 8, this->TexFontSize.y * 37, this->TexFontSize.x * 9, this->TexFontSize.y * 38)));
		this->func.insert(std::make_pair("０", Box2D(this->TexFontSize.x * 9, this->TexFontSize.y * 37, this->TexFontSize.x * 10, this->TexFontSize.y * 38)));
	}
	//未完成
	this->func.insert(std::make_pair("a", Box2D(0.f, this->TexHalfFontSize.y * 38, 33.f, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("b", Box2D(33.f, this->TexHalfFontSize.y * 38, 74.f, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("c", Box2D(74.f, this->TexHalfFontSize.y * 38, 109.f, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("d", Box2D(107.f, this->TexHalfFontSize.y * 38, 144.f, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("e", Box2D(144.f, this->TexHalfFontSize.y * 38, 179.f, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("f", Box2D(179.f, this->TexHalfFontSize.y * 38, 207.f, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("g", Box2D(204.f, this->TexHalfFontSize.y * 38 + 20.f, 239.f, this->TexHalfFontSize.y * 39 + 20.f)));
	this->func.insert(std::make_pair("h", Box2D(238.f, this->TexHalfFontSize.y * 38, 280.f, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("i", Box2D(280.f, this->TexHalfFontSize.y * 38, 302.f, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("j", Box2D(300.f, this->TexHalfFontSize.y * 38, 320.f, this->TexHalfFontSize.y * 39 + 20.f)));
	this->func.insert(std::make_pair("k", Box2D(320.f, this->TexHalfFontSize.y * 38, 364.f, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("l", Box2D(this->TexHalfFontSize.x * 11, this->TexHalfFontSize.y * 38, this->TexHalfFontSize.x * 12, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("m", Box2D(this->TexHalfFontSize.x * 12, this->TexHalfFontSize.y * 38, this->TexHalfFontSize.x * 13, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("n", Box2D(this->TexHalfFontSize.x * 13, this->TexHalfFontSize.y * 38, this->TexHalfFontSize.x * 14, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("o", Box2D(this->TexHalfFontSize.x * 14, this->TexHalfFontSize.y * 38, this->TexHalfFontSize.x * 15, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("p", Box2D(this->TexHalfFontSize.x * 15, this->TexHalfFontSize.y * 38, this->TexHalfFontSize.x * 16, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("q", Box2D(this->TexHalfFontSize.x * 16, this->TexHalfFontSize.y * 38, this->TexHalfFontSize.x * 17, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("r", Box2D(this->TexHalfFontSize.x * 17, this->TexHalfFontSize.y * 38, this->TexHalfFontSize.x * 18, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("s", Box2D(this->TexHalfFontSize.x * 18, this->TexHalfFontSize.y * 38, this->TexHalfFontSize.x * 19, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("t", Box2D(this->TexHalfFontSize.x * 19, this->TexHalfFontSize.y * 38, this->TexHalfFontSize.x * 20, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("u", Box2D(this->TexHalfFontSize.x * 20, this->TexHalfFontSize.y * 38, this->TexHalfFontSize.x * 21, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("v", Box2D(this->TexHalfFontSize.x * 21, this->TexHalfFontSize.y * 38, this->TexHalfFontSize.x * 22, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("w", Box2D(this->TexHalfFontSize.x * 22, this->TexHalfFontSize.y * 38, this->TexHalfFontSize.x * 23, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("x", Box2D(this->TexHalfFontSize.x * 23, this->TexHalfFontSize.y * 38, this->TexHalfFontSize.x * 24, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("y", Box2D(this->TexHalfFontSize.x * 24, this->TexHalfFontSize.y * 38, this->TexHalfFontSize.x * 25, this->TexHalfFontSize.y * 39)));
	this->func.insert(std::make_pair("z", Box2D(this->TexHalfFontSize.x * 25, this->TexHalfFontSize.y * 38, this->TexHalfFontSize.x * 26, this->TexHalfFontSize.y * 39)));

	this->func.insert(std::make_pair("A", Box2D(0.f, this->TexHalfFontSize.y * 39, 33.f, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("B", Box2D(this->TexHalfFontSize.x * 1, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 2, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("C", Box2D(this->TexHalfFontSize.x * 2, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 3, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("D", Box2D(this->TexHalfFontSize.x * 3, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 4, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("E", Box2D(this->TexHalfFontSize.x * 4, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 5, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("F", Box2D(this->TexHalfFontSize.x * 5, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 6, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("G", Box2D(this->TexHalfFontSize.x * 6, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 7, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("H", Box2D(this->TexHalfFontSize.x * 7, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 8, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("I", Box2D(this->TexHalfFontSize.x * 8, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 9, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("J", Box2D(this->TexHalfFontSize.x * 9, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 10, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("K", Box2D(this->TexHalfFontSize.x * 10, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 11, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("L", Box2D(this->TexHalfFontSize.x * 11, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 12, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("M", Box2D(this->TexHalfFontSize.x * 12, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 13, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("N", Box2D(this->TexHalfFontSize.x * 13, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 14, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("O", Box2D(this->TexHalfFontSize.x * 14, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 15, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("P", Box2D(this->TexHalfFontSize.x * 15, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 16, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("Q", Box2D(this->TexHalfFontSize.x * 16, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 17, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("R", Box2D(this->TexHalfFontSize.x * 17, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 18, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("S", Box2D(this->TexHalfFontSize.x * 18, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 19, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("T", Box2D(this->TexHalfFontSize.x * 19, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 20, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("U", Box2D(this->TexHalfFontSize.x * 20, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 21, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("V", Box2D(this->TexHalfFontSize.x * 21, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 22, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("W", Box2D(this->TexHalfFontSize.x * 22, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 23, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("X", Box2D(this->TexHalfFontSize.x * 23, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 24, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("Y", Box2D(this->TexHalfFontSize.x * 24, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 25, this->TexHalfFontSize.y * 40)));
	this->func.insert(std::make_pair("Z", Box2D(this->TexHalfFontSize.x * 25, this->TexHalfFontSize.y * 39, this->TexHalfFontSize.x * 26, this->TexHalfFontSize.y * 40)));
}