#pragma once
#include "System/System_.h"
#include "OG\OGlib.h"
#include "Texture\Texture.h"
#include "ResourceManager\ResourceManager.h"
#include "Engine\Framework.h"
/**
*@brief OpenGL Features
*/
class OGSystem_
{
	static void Render(Texture_* texture, const GLfloat* vtx, const GLfloat* uv, const GLfloat* color)
	{
		glAlphaFunc(GL_GREATER, (GLclampf)0.0);
		texture->GetShader()->Use();
		GLint in_posLocation = texture->GetShader()->Attrib("inpos");
		GLint in_uvLocation = texture->GetShader()->Attrib("inuv");
		GLint in_texture = texture->GetShader()->Uniform("tex");
		GLuint in_color = texture->GetShader()->Attrib("incolor");
		GLuint in_proj = texture->GetShader()->Uniform("viewMatrix");

		glEnableVertexAttribArray(in_posLocation);
		glEnableVertexAttribArray(in_uvLocation);
		glEnableVertexAttribArray(in_color);

		glUniform1f(in_texture, 0);
		glUniformMatrix4fv(in_proj, 1, GL_FALSE, Framework::Get()->GetScene()->GetCamera()->GetProjectionMatrix());

		glVertexAttribPointer(in_posLocation, 2, GL_FLOAT, false, 0, vtx);
		glVertexAttribPointer(in_uvLocation, 2, GL_FLOAT, false, 0, uv);
		glVertexAttribPointer(in_color, 4, GL_FLOAT, false, 0, color);

		glBindTexture(GL_TEXTURE_2D, texture->GetID());
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	}
	static void Rotate(const float radian, GLfloat* matrix)
	{
		//ラジアンの値に変更
		float tora = OG::ToRadian(radian);
		//原点を指定
		Vec2 Center((*(matrix + 2) + *(matrix)) / 2, (*(matrix + 5) + *(matrix + 1)) / 2);
		//回転軸の原点の値を導く
		GLfloat v[]
		{
			*(matrix)-Center.x,*(matrix + 1) - Center.y,
			*(matrix + 2) - Center.x,*(matrix + 3) - Center.y,
			*(matrix + 4) - Center.x,*(matrix + 5) - Center.y,
			*(matrix + 6) - Center.x,*(matrix + 7) - Center.y,
		};
		//回転行列の生成
		GLfloat ma[4] = {
			cosf(tora),-sinf(tora),
			sinf(tora),cosf(tora),
		};
		//回転行列の計算
		*(matrix) = (*(v) * *(ma)) + (*(v + 1)* *(ma + 1));
		*(matrix + 1) = (*(v)* *(ma + 2)) + (*(v + 1)* *(ma + 3));

		*(matrix + 2) = (*(v + 2)* *(ma)) + (*(v + 3)* *(ma + 1));
		*(matrix + 3) = (*(v + 2)* *(ma + 2)) + (*(v + 3)* *(ma + 3));

		*(matrix + 4) = (*(v + 4)* *(ma)) + (*(v + 5)* *(ma + 1));
		*(matrix + 5) = (*(v + 4)* *(ma + 2)) + (*(v + 5)* *(ma + 3));

		*(matrix + 6) = (*(v + 6)* *(ma)) + (*(v + 7)* *(ma + 1));
		*(matrix + 7) = (*(v + 6)* *(ma + 2)) + (*(v + 7)* *(ma + 3));

		//回転軸の原点の移動した分を元に戻す
		*(matrix) = *(matrix)+Center.x;
		*(matrix + 1) = *(matrix + 1) + Center.y;

		*(matrix + 2) = *(matrix + 2) + Center.x;
		*(matrix + 3) = *(matrix + 3) + Center.y;

		*(matrix + 4) = *(matrix + 4) + Center.x;
		*(matrix + 5) = *(matrix + 5) + Center.y;

		*(matrix + 6) = *(matrix + 6) + Center.x;
		*(matrix + 7) = *(matrix + 7) + Center.y;
	}
	static Box2D GetAbsolute(const Transform* transform)
	{
		Box2D draw(transform->position, transform->scale);
		draw.OffsetCenterSize();
		return draw;
	}
public:
	static void Draw(Texture_* texture, const Transform* transform)
	{
		Draw(texture, &GetAbsolute(transform), 0.0f, &Color());
	}
	static void Draw(Texture_* texture, const Transform* transform, const float angle)
	{
		Draw(texture, &GetAbsolute(transform), angle, &Color());
	}
	static void Draw(Texture_* texture, const Transform* transform, const Color* color)
	{
		Draw(texture, &GetAbsolute(transform), 0.0f, color);
	}
	static void Draw(Texture_* texture, const Transform* transform, const float angle, const Color* color)
	{
		Draw(texture, &GetAbsolute(transform), angle, color);
	}
	static void Draw(Texture_* texture, const Transform* transform, const Box2D* src, const Color* color)
	{
		Draw(texture, &GetAbsolute(transform), src, transform->angle, color);
	}
	static void Draw(Texture_* texture, const Transform* draw, const Transform* src)
	{
		Draw(texture, &GetAbsolute(draw), &GetAbsolute(src), draw->angle, &Color(1, 1, 1, 1));
	}
	static void Draw(Texture_* texture, const const Transform* draw, const Transform* src, const Color* color)
	{
		Draw(texture, &GetAbsolute(draw), &GetAbsolute(src), draw->angle, color);
	}
	static void Draw(Texture_* texture, const Box2D* draw)
	{
		Draw(texture, draw, 0.0f, &Color());
	}
	static void Draw(Texture_* texture, const Box2D* draw, const float angle)
	{
		Draw(texture, draw, angle, &Color());
	}
	static void Draw(Texture_* texture, const Box2D* draw, const Color* color)
	{
		Draw(texture, draw, 0.0f, color);
	}
	static void Draw(Texture_* texture, const Box2D* draw, const float angle,const Color* color)
	{
		GLfloat vtx[] = {
			draw->x,draw->h,
			draw->w,draw->h,
			draw->w,draw->y,
			draw->x,draw->y,
		};
		Rotate(angle, &vtx[0]);
		const GLfloat texuv[] = {
			1.f,1.f,
			1.f,1.f,
			1.f,1.f,
			1.f,1.f,
		};
		const GLfloat texcolor[] = {
			color->red,
			color->green,
			color->blue,
			color->alpha,
			color->red,
			color->green,
			color->blue,
			color->alpha,
			color->red,
			color->green,
			color->blue,
			color->alpha,
			color->red,
			color->green,
			color->blue,
			color->alpha,
		};
		Render(texture, vtx, texuv, texcolor);
	}
	static void Draw(Texture_* texture, const Box2D* draw, const Box2D* src)
	{
		Draw(texture, draw, src, 0.0f, &Color());
	}
	static void Draw(Texture_* texture, const Box2D* draw, const Box2D* src, const float angle, const Color* color)
	{
		GLfloat vtx[] = {
		draw->x,draw->h,
		draw->w,draw->h,
		draw->w,draw->y,
		draw->x,draw->y,
		};
		Rotate(angle, &vtx[0]);
		const GLfloat texuv[] = {
			src->x / texture->GetSize()->x,src->h / texture->GetSize()->y,
			src->w / texture->GetSize()->x,src->h / texture->GetSize()->y,
			src->w / texture->GetSize()->x,src->y / texture->GetSize()->y,
			src->x / texture->GetSize()->x,src->y / texture->GetSize()->y,
		};
		const GLfloat texcolor[] = {
			color->red,
			color->green,
			color->blue,
			color->alpha,
			color->red,
			color->green,
			color->blue,
			color->alpha,
			color->red,
			color->green,
			color->blue,
			color->alpha,
			color->red,
			color->green,
			color->blue,
			color->alpha,
		};
		Render(texture, vtx, texuv, texcolor);
	}
};