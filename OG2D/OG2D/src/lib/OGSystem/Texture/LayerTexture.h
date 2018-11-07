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
	*@brief	�o�^���C���[��S�`�悷��
	*@param[in] Box2D& draw OriginPosition
	*/
	void Draw(const Box2D& draw);
	/**
	*@brief	���C���[��o�^����
	*@param[in] string& name �o�^��
	*@param[in] Texture* tex TextureData
	*/
	void Push(const std::string& name, Texture* tex);
	/**
	*@brief	�o�^���C���[���폜����
	*@param[in] string& name �o�^��
	*/
	void Erase(const std::string& name);
	/**
	*@brief	���C���[���擾
	*@param[in] string& name �o�^��
	*@return LayerData* Data
	*/
	LayerData* Get(const std::string& name);
	/**
	*@brief �`�揇��o�^����
	*/
	void SetDrawOrder();
};