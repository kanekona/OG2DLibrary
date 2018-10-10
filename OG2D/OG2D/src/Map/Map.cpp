#include "Map.h"

Map::Map()
{
	this->chip_Image = rm->GetTextureData("");
}
Map::~Map()
{

}
Map* Map::Create()
{
	return new Map();
}

Map::Base::Base()
{
	this->arr = 0;
	this->id = nullptr;
}
Map::Base::~Base()
{
	if (this->id)
	{
		delete this->id;
		this->id = nullptr;
	}
}

bool Map::Base::IDCheck(const int id)
{
	if (this->id)
	{
		return *this->id <= id ? true : false;
	}
	return false;
}

bool Map::Base::ChipCheck(const int chip)
{
	return this->arr == chip ? true : false;
}
void Map::Base::Setarr(const int _arr)
{
	this->arr = _arr;
}
void Map::Base::SetID(const int id)
{
	if (!this->id)
	{
		this->id = new int(id);
	}
	else
	{
		*this->id = id;
	}
}
int Map::Base::Getarr() const
{
	return this->arr;
}
int* Map::Base::GetID() const
{
	return this->id;
}