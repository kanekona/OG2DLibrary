#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Shader\shader.h"
//--------------------------------------------------
//@:Textureclass									
//--------------------------------------------------
bool Texture::Create(const std::string& path)
{
	return this->Init(path);
}
Texture::Texture()
	:FileName("./data/image/")
{
	OG::Destroy<GLuint>(this->_TexId);
	if (!this->_TexId)
	{
		this->_TexId = new GLuint;
		//テクスチャを1つだけ生成する
		this->CreateID(1);
	}
	//テクスチャをバインドする
	this->Bind(*this->_TexId);
	//nullデータを登録
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
}
Texture::Texture(const std::string& path)
	:FileName("./data/image/")
{
	OG::Destroy<GLuint>(this->_TexId);
	this->Init(path);
}
bool Texture::Init(const std::string& path)
{
	if (!this->_TexId)
	{
		this->_TexId = new GLuint;
		//テクスチャを1つだけ生成する
		this->CreateID(1);
	}
	//テクスチャをバインドする
	this->Bind(*this->_TexId);
	//画像を読み込む
	int width;
	int height;
	int comp;
	std::string filepath = FileName + path;
	//画像データを読み込む
	unsigned char *data = stbi_load(filepath.c_str(), &width, &height, &comp, 0);
	if (data == NULL)
	{
		std::cout << "Texture Create Error!" << path << "\n";
		OG::OutDebugData("TextureErrorPath.og", path + "\n");
		this->Finalize();
		OG::Destroy<GLuint>(this->_TexId);
		return false;
	}
	//データ形式を選ぶ
	GLint type = (comp == 3) ? GL_RGB : GL_RGBA;
	//画像データをOpenGLへ送る
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, data);
	this->TextureSize = Vec2(width, height);
	//元データの破棄
	stbi_image_free(data);
	//表示用設定
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	this->angle = 0.f;
	return true;
}
void Texture::SetBuffer(void* data, const unsigned int w, const unsigned int h)
{
	//テクスチャをバインドする
	this->Bind(*this->_TexId);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RED, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);	
	this->TextureSize = Vec2((int)w, (int)h);
}
//void Texture::Draw(const Box2D& draw, const Box2D& src,const Color& color_) {
//	//座標
//	GLfloat vtx[] = {
//		draw.x,draw.h,
//		draw.w,draw.h,
//		draw.w,draw.y,
//		draw.x,draw.y,
//	};
//	_Rotate(angle, &vtx[0]);
//	glVertexPointer(2, GL_FLOAT, 0, vtx);
//	//画像座標
//	const GLfloat texuv[] = {
//		src.x / TextureSize.x,src.h / TextureSize.y,
//		src.w / TextureSize.x,src.h / TextureSize.y,
//		src.w / TextureSize.x,src.y / TextureSize.y,
//		src.x / TextureSize.x,src.y / TextureSize.y,
//	};
//	//0.1以下のカラーを表示しない、これで透過されてる部分を切り抜くことで透過された画像になる
//	glAlphaFunc(GL_GREATER, (GLclampf)0.0);
//	glTexCoordPointer(2, GL_FLOAT, 0, texuv);
//	//OpenGLに登録されているテクスチャを紐づけ
//	glBindTexture(GL_TEXTURE_2D, *this->_TexId);
//	glColor4f(color_.red, color_.green, color_.blue, color_.alpha);
//	//描画
//	//glMatrixMode(GL_TEXTURE);
//	glEnable(GL_ALPHA_TEST);
//	glEnable(GL_TEXTURE_2D);
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//	glDrawArrays(GL_QUADS, 0, 4);
//	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//	glDisableClientState(GL_VERTEX_ARRAY);
//	glDisable(GL_TEXTURE_2D);
//	glDisable(GL_ALPHA_TEST);
//	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
//	glBindTexture(GL_TEXTURE_2D, 0);
//}
void Texture::Draw(const Box2D& draw, const Box2D& src, const Color& color_) {
		//座標
		GLfloat vtx[] = {
			draw.x,draw.h,
			draw.w,draw.h,
			draw.w,draw.y,
			draw.x,draw.y,
		};
		_Rotate(angle, &vtx[0]);
		glVertexPointer(2, GL_FLOAT, 0, vtx);
		//画像座標
		const GLfloat texuv[] = {
			src.x / TextureSize.x,src.h / TextureSize.y,
			src.w / TextureSize.x,src.h / TextureSize.y,
			src.w / TextureSize.x,src.y / TextureSize.y,
			src.x / TextureSize.x,src.y / TextureSize.y,
		};
		const GLfloat color[] = {
			color_.red,
			color_.green,
			color_.blue,
			color_.alpha
		};
		//0.1以下のカラーを表示しない、これで透過されてる部分を切り抜くことで透過された画像になる
		glAlphaFunc(GL_GREATER, (GLclampf)0.0);
		glTexCoordPointer(2, GL_FLOAT, 0, texuv);
		//OpenGLに登録されているテクスチャを紐づけ
		glBindTexture(GL_TEXTURE_2D, *this->_TexId);
		glColor4f(color_.red, color_.green, color_.blue, color_.alpha);
			//描画
			//glMatrixMode(GL_TEXTURE);
			glEnable(GL_ALPHA_TEST);
			glEnable(GL_TEXTURE_2D);
			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glDrawArrays(GL_QUADS, 0, 4);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
			glDisableClientState(GL_VERTEX_ARRAY);
			glDisable(GL_TEXTURE_2D);
			glDisable(GL_ALPHA_TEST);
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			glBindTexture(GL_TEXTURE_2D, 0);
	}
bool Texture::Finalize()
{
	this->Bind(0);
	if (this->_TexId)
	{
		this->DeleteID(1);
		OG::Destroy<GLuint>(this->_TexId);
	}
	return true;
}
void Texture::Rotate(const float radian)
{
	this->angle = radian;
}
void Texture::_Rotate(const float radian, GLfloat *_mate)
{
	//ラジアンの値に変更
	float tora = OG::ToRadian(radian);
	//原点を指定
	Vec2 Center((*(_mate + 2) + *(_mate)) / 2, (*(_mate + 5) + *(_mate + 1)) / 2);
	//回転軸の原点の値を導く
	GLfloat v[]
	{
		*(_mate)-Center.x,*(_mate + 1) - Center.y,
		*(_mate + 2) - Center.x,*(_mate + 3) - Center.y,
		*(_mate + 4) - Center.x,*(_mate + 5) - Center.y,
		*(_mate + 6) - Center.x,*(_mate + 7) - Center.y,
	};
	//回転行列の生成
	GLfloat ma[4] = {
		cosf(tora),-sinf(tora),
		sinf(tora),cosf(tora),
	};
	//回転行列の計算
	*(_mate) = (*(v) * *(ma)) + (*(v + 1)* *(ma + 1));
	*(_mate + 1) = (*(v)* *(ma + 2)) + (*(v + 1)* *(ma + 3));

	*(_mate + 2) = (*(v + 2)* *(ma)) + (*(v + 3)* *(ma + 1));
	*(_mate + 3) = (*(v + 2)* *(ma + 2)) + (*(v + 3)* *(ma + 3));

	*(_mate + 4) = (*(v + 4)* *(ma)) + (*(v + 5)* *(ma + 1));
	*(_mate + 5) = (*(v + 4)* *(ma + 2)) + (*(v + 5)* *(ma + 3));

	*(_mate + 6) = (*(v + 6)* *(ma)) + (*(v + 7)* *(ma + 1));
	*(_mate + 7) = (*(v + 6)* *(ma + 2)) + (*(v + 7)* *(ma + 3));

	//回転軸の原点の移動した分を元に戻す
	*(_mate) = *(_mate)+Center.x;
	*(_mate + 1) = *(_mate + 1) + Center.y;

	*(_mate + 2) = *(_mate + 2) + Center.x;
	*(_mate + 3) = *(_mate + 3) + Center.y;

	*(_mate + 4) = *(_mate + 4) + Center.x;
	*(_mate + 5) = *(_mate + 5) + Center.y;

	*(_mate + 6) = *(_mate + 6) + Center.x;
	*(_mate + 7) = *(_mate + 7) + Center.y;
}
Vec2 Texture::GetTextureSize() const
{
	return this->TextureSize;
}
Texture::~Texture()
{
	this->Bind(0);
	if (this->_TexId)
	{
		this->DeleteID(1);
		OG::Destroy<GLuint>(this->_TexId);
	}
}
GLuint Texture::GetID() const
{
	return *this->_TexId;
}
GLuint Texture::CreateID(const GLsizei& size)
{
	glGenTextures(size, this->_TexId);
	return *this->_TexId;
}
void Texture::DeleteID(const GLsizei& size)
{
	glDeleteTextures(size, this->_TexId);
}
void Texture::Bind(const GLuint& id)
{
	glBindTexture(GL_TEXTURE_2D, id);
}