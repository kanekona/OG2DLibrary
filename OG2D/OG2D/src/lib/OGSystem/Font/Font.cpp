#include "Font.h"
TestFont::TestFont()
{
	FT_Init_FreeType(&this->ft_library);
	if (!this->ft_library)
	{
		std::cout << "FontInitError" << std::endl;
		return;
	}
	FT_New_Face(this->ft_library, "data/font/msgothic.ttc", 0, &this->face);
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
			FT_Get_Char_Index(this->face, t);
			FT_Load_Char(this->face, t, FT_LOAD_RENDER);
			FT_Render_Glyph(this->face->glyph, FT_Render_Mode::FT_RENDER_MODE_NORMAL);

			FT_Bitmap bitmap = this->face->glyph->bitmap;
			TextureData data;
			data.character = t;
			data.texture = new Texture();
			data.size = { (int)face->glyph->bitmap.width,(int)face->glyph->bitmap.rows };
			data.bearing = { face->glyph->bitmap_left,face->glyph->bitmap_top };
			data.texture->SetBuffer(bitmap.buffer, bitmap.width, bitmap.rows);
			this->datas.emplace_back(data);
			//delete[] textbuffer;
		}
	}
	for (int i = 0; i < text.size(); ++i)
	{
		for (auto& id : datas)
		{
			if (id.character == text[i])
			{
				float pos_x = pos.x + (fontSize*i);
				Box2D draw(Vec2(pos_x, pos.y), Vec2((int)fontSize, (int)fontSize));
				draw.OffsetSize();
				Box2D src(Vec2(), id.texture->GetTextureSize());
				id.texture->Draw(draw, src);
				break;
			}
		}
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