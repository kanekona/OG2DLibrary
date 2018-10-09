///–¢ŽÀ‘•
#pragma once
#include "ft2build.h"
#include FT_FREETYPE_H

#include "OGSystem\Texture\Texture.h"

class TestFont
{
	struct TextureData
	{
		Texture* texture;
		Vec2 size;
		Vec2 bearing;
		wchar_t character;
	};
public:
	std::vector<TextureData> datas;
	explicit TestFont();
	virtual ~TestFont();
	FT_Library ft_library;
	FT_Face face;
	void Draw(const std::string& text, unsigned int fontSize, const Vec2& pos);
	GLuint texID;
	bool Check(char);
};