#include "Font.h"
TestFont::TestFont()
{
	FT_Init_FreeType(&this->ft_library);
	if (!this->ft_library)
	{
		std::cout << "FontInitError" << std::endl;
		return;
	}
	//"" -> 使用フォント指定
	/*FT_Error error = */FT_New_Face(this->ft_library, "data/font/msgothic.ttc", 0, &this->face);
}
TestFont::~TestFont()
{
	for (auto& id : this->datas)
	{
		delete id.texture;
	}
	FT_Done_Face(this->face);
	FT_Done_FreeType(this->ft_library);
}
void TestFont::Draw(const std::string& text, unsigned int fontSize, const Vec2& pos)
{
	for (auto t : text)
	{
		if (this->Check(t))
		{
			FT_Set_Pixel_Sizes(this->face, fontSize, fontSize);
			FT_Load_Glyph(this->face, FT_Get_Char_Index(this->face, t), FT_LOAD_RENDER);

			FT_Bitmap bitmap = this->face->glyph->bitmap;
			TextureData data;
			char* textbuffer = new char[bitmap.width * bitmap.rows];
			unsigned int count = 0;
			for (int y = bitmap.rows - 1; y >= 0; --y)
			{
				for (unsigned int x = 0; x < bitmap.width; ++x)
				{
					textbuffer[count] = bitmap.buffer[y * bitmap.width + x];
					++count;
				}
			}
			data.character = t;
			data.texture = new Texture();
			data.texture->SetBuffer(textbuffer, bitmap.width, bitmap.rows - 1);
			this->datas.emplace_back(data);
			delete[] textbuffer;
		}
	}
	for (auto& t : this->datas)
	{
		Box2D draw(pos, Vec2((int)fontSize, (int)fontSize));
		draw.OffsetSize();
		Box2D src(Vec2(), t.texture->GetTextureSize());
		t.texture->Draw(draw, src);
	}
}

bool TestFont::Check(char c)
{
	for (auto& id : this->datas)
	{
		if (id.character == c)
		{
			return false;
		}
	}
	return true;
}