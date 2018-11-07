#include "LayerTexture.h"
LayerData::LayerData()
{
	this->image = nullptr;
	this->color = { 1,1,1,1 };
	this->offset = { 0,0,0,0 };
	this->order = 0;
}
void LayerData::Draw(const Box2D& draw)
{
	Box2D b(this->offset + draw);
	b.OffsetCenterSize();
	this->image->Draw(b, this->src, this->color);
}
LayerTexture::~LayerTexture()
{
	for (auto& id : this->layer)
	{
		OG::Destroy<LayerData>(id.second);
	}
	this->layer.clear();
}
void LayerTexture::Draw(const Box2D& draw)
{
	for (int i = 0; i < this->layer.size(); ++i)
	{
		this->layer[this->order[i].id].second->Draw(draw);
	}
}
void LayerTexture::Push(const std::string& name, Texture* tex)
{
	std::pair<std::string, LayerData*> data;
	LayerData* d = new LayerData;
	d->image = tex;
	d->src = { Vec2(),d->image->GetTextureSize() };
	data.first = name;
	data.second = d;
	this->layer.emplace_back(data);
}
void LayerTexture::Erase(const std::string& name)
{
	for (auto id = this->layer.begin(); id != this->layer.end(); ++id)
	{
		if (id->first == name)
		{
			OG::Destroy<LayerData>(id->second);
			this->layer.erase(id);
			return;
		}
	}
}
LayerData* LayerTexture::Get(const std::string& name)
{
	for (int i = 0; i < this->layer.size(); ++i)
	{
		if (this->layer[i].first == name)
		{
			return this->layer[i].second;
		}
	}
	return nullptr;
}
void LayerTexture::SetDrawOrder()
{
	this->order.resize(this->layer.size());
	//‰Šúó‘Ô‚ğƒRƒs[‚·‚é
	for (int i = 0; i < this->layer.size(); ++i)
	{
		this->order[i].id = i;
		this->order[i].order_s = this->layer[i].second->order;
	}
	//•`‰æ‡‚É‡‚í‚¹‚Äid‚Æorder‚ğ•À‚Ñ‘Ö‚¦‚é
	for (int i = 0; i < this->layer.size(); ++i)
	{
		for (int j = i; j < this->layer.size(); ++j)
		{
			if (this->order[i].order_s > this->order[j].order_s)
			{
				OrderCheck kari = this->order[i];
				this->order[i] = this->order[j];
				this->order[j] = kari;
			}
		}
	}
}