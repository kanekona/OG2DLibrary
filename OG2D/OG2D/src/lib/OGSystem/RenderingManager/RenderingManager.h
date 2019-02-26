#pragma once
//#include "Entity/Entity.h"
#include "Sprite\Sprite.h"
#include <vector>
/**
*@brief	•`‰æ‚ğ‚Ü‚Æ‚ß‚Äs‚¤class
•`‰æ‡‚ğ‚Ü‚Æ‚ß‚é‚±‚Æ‚ğl‚¦‚é‚Æ“o˜^—p•Ï”‚ª‚ ‚Á‚½•û‚¢‚¢‚©‚È

*/
class RenderingManager
{
	//! Front Canvas
	std::vector<Sprite*> uiCanvas;
	//! Canvas
	std::vector<Sprite*> canvas;
	//! Back Canvas
	std::vector<Sprite*> backCanvas;
	//! Plans Front Canvas
	std::vector<Sprite*> plansUIs;
	//! Plans Canvas
	std::vector<Sprite*> plansCanvas;
	//! Plans Back Canvas
	std::vector<Sprite*> plansBacks;
	/**
	*@brief	order sort
	*/
	void CanvasOrderSort();
	/**
	*@brief UIRendering
	*/
	void UIRendering();
	/**
	*@brief	CanvasRendering
	*/
	void CanvasRendering();
	/**
	*@brief	BackRendering
	*/
	void BackRendering();
	/**
	*@brief	Rendering
	*/
	void Render();
	/**
	*@brief	UI Sprite Adaptation
	*/
	void UIStateAdaptation();
	/**
	*@brief	Canvas Sprite Adaptation
	*/
	void CanvasStateAdaptation();
	/**
	*@brief	Back Sprite Adaptation
	*/
	void BackStateAdaptation();
	/**
	*@brief	All Sprite Adaptation
	*/
	void AllStateAdaptation();
	/**
	*@brief	Canvas Sprite Adaptation
	*/
	template <class T> void CanvasAdaptation(std::vector<T*>* now, std::vector<T*>* plans)
	{
		for (auto it = now->begin(); it != now->end();)
		{
			if (*it != nullptr)
			{
				++it;
			}
			else
			{
				it = now->erase(it);
			}
		}
		for (auto it : *plans)
		{
			now->emplace_back(it);
		}
		plans->clear();
	}
public:
	/**
	*@brief	constructor
	*/
	explicit RenderingManager();
	/**
	*@brief destructor
	*/
	virtual ~RenderingManager();
	/**
	*@brief	Add Sprite to Canvas
	*@param[in] Sprite* sprite Add Data
	*/
	void AddSpriteCanvas(Sprite* sprite);
	/**
	*@brief	Add Sprite to UICanvas
	*@param[in] Sprite* sprite Add Data
	*/
	void AddSpriteUI(Sprite* sprite);
	/**
	*@brief	Add Sprite to BackCanvas
	*@param[in] Sprite* sprite Add Data
	*/
	void AddSpriteBack(Sprite* sprite);
	/**
	*@brief	AllCanvasRendering
	*@param[in] RenderingManager* renderingManager this
	*/
	static void Render(RenderingManager* renderingManager);
	/**
	*@brief	All Sprite Adaptation
	*@param[in] RenderingManager* renderingManager this
	*/
	static void AllSpriteAdaptation(RenderingManager* renderingManager);
};