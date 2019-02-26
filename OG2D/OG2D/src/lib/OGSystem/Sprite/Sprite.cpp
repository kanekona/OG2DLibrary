#include "Sprite.h"
#include "Engine\Framework.h"
#include "OG\OGSystem_.hpp"
Sprite::Sprite(const int registerd)
{
	this->Register(registerd);
}
Sprite::~Sprite()
{

}
void Sprite::Register(const int registerd)
{
	//SceneManager経由でRenderingManagerに自分を登録する
	switch (registerd)
	{
	case REGISTERD_CANVAS:
		Framework::Get()->GetScene()->GetRenderingManager().AddSpriteCanvas(this);
		break;
	case REGISTERD_UI:
		Framework::Get()->GetScene()->GetRenderingManager().AddSpriteUI(this);
		break;
	case REGISTERD_BACK:
		Framework::Get()->GetScene()->GetRenderingManager().AddSpriteBack(this);
		break;
	default:
		//エラー出力
		break;
	}
}
void Sprite::SetTexture(Texture_ tex)
{
	texture = tex;
	//↓なにこれ？？？俺覚えてない、一応残しておく
	//Framework::Get()->;
}
void Sprite::Draw()
{
	OGSystem_::Draw(&texture, &this->transform);
}