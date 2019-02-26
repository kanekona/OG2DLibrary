#include "RenderingManager.h"

RenderingManager::RenderingManager()
{

}
RenderingManager::~RenderingManager()
{

}
void RenderingManager::CanvasOrderSort()
{
	//未実装はよ書け
}
void RenderingManager::UIRendering()
{
	for (auto it : uiCanvas)
	{
		it->Draw();
	}
}
void RenderingManager::CanvasRendering()
{
	for (auto it : canvas)
	{
		it->Draw();
	}
}
void RenderingManager::BackRendering()
{
	for (auto it : backCanvas)
	{
		it->Draw();
	}
}
void RenderingManager::Render()
{
	this->UIRendering();
	this->CanvasRendering();
	this->BackRendering();
}
void RenderingManager::UIStateAdaptation()
{
	//削除
	for (auto it = uiCanvas.begin(); it != uiCanvas.end();)
	{
		if (*it != nullptr)
		{
			++it;
		}
		else
		{
			it = uiCanvas.erase(it);
		}
	}
	//登録
	for (auto it : plansUIs)
	{
		uiCanvas.emplace_back(it);
		//EnterはEntityの登録時に呼ばれるのでここでは特に行わない
	}
	plansUIs.clear();
}
void RenderingManager::CanvasStateAdaptation()
{
	for (auto it = canvas.begin(); it != canvas.end();)
	{
		if (*it != nullptr)
		{
			++it;
		}
		else
		{
			it = canvas.erase(it);
		}
	}
	for (auto it : plansCanvas)
	{
		canvas.emplace_back(it);
	}
	plansCanvas.clear();
}
void RenderingManager::BackStateAdaptation()
{
	for (auto it = backCanvas.begin(); it != backCanvas.end();)
	{
		if (*it != nullptr)
		{
			++it;
		}
		else
		{
			it = backCanvas.erase(it);
		}
	}
	for (auto it : plansBacks)
	{
		backCanvas.emplace_back(it);
	}
	plansBacks.clear();
}
void RenderingManager::AllStateAdaptation()
{
	//UIStateAdaptation();
	//CanvasStateAdaptation();
	//BackStateAdaptation();
	CanvasAdaptation<Sprite>(&uiCanvas, &plansUIs);
	CanvasAdaptation<Sprite>(&canvas, &plansCanvas);
	CanvasAdaptation<Sprite>(&backCanvas, &plansBacks);
}
void RenderingManager::AddSpriteCanvas(Sprite* sprite)
{
	plansCanvas.emplace_back(sprite);
}
void RenderingManager::AddSpriteUI(Sprite* sprite)
{
	plansUIs.emplace_back(sprite);
}
void RenderingManager::AddSpriteBack(Sprite* sprite)
{
	plansBacks.emplace_back(sprite);
}
void RenderingManager::Render(RenderingManager* manager)
{
	manager->Render();
}
void RenderingManager::AllSpriteAdaptation(RenderingManager* manager)
{
	manager->AllStateAdaptation();
}