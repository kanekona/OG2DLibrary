#pragma once
#include "Texture.h"
#include "Order\Order.h"
struct LayerData
{
	Texture* image;
	Box2D offset;
	Color color;
	Box2D src;
	unsigned int order;
	explicit LayerData();
	void Draw(const Box2D& draw);
};
class LayerTexture
{
public:
	//! LayerData
	std::vector<std::pair<std::string, LayerData*>> layer;
	//! DrawOrder
	std::vector<OrderCheck> order;
	/**
	*@brief	destructor
	*/
	virtual ~LayerTexture();
	/**
	*@brief	“o˜^ƒŒƒCƒ„[‚ğ‘S•`‰æ‚·‚é
	*@param[in] Box2D& draw OriginPosition
	*/
	void Draw(const Box2D& draw);
	/**
	*@brief	ƒŒƒCƒ„[‚ğ“o˜^‚·‚é
	*@param[in] string& name “o˜^–¼
	*@param[in] Texture* tex TextureData
	*/
	void Push(const std::string& name, Texture* tex);
	/**
	*@brief	“o˜^ƒŒƒCƒ„[‚ğíœ‚·‚é
	*@param[in] string& name “o˜^–¼
	*/
	void Erase(const std::string& name);
	/**
	*@brief	ƒŒƒCƒ„[‚ğæ“¾
	*@param[in] string& name “o˜^–¼
	*@return LayerData* Data
	*/
	LayerData* Get(const std::string& name);
	/**
	*@brief •`‰æ‡‚ğ“o˜^‚·‚é
	*/
	void SetDrawOrder();
};