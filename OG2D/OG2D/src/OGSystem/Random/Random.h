///ランダムの数値、文字列を取得するためのclass
///既存GameEngineを使用している場合は自動で生成、初期化される
#pragma once
#include <random>
#include <iostream>
//ランダム生成名前空間
namespace random
{
	static std::mt19937_64 engine;				//メルセンヌツイスター64bit
	void Init();								//初期化
	int GetRand(const int min_,const int max_);				//整数のランダム
	float GetRand(const float min_,const float max_);		//浮動小数点のランダム
	std::string GetRand(						//文字列のランダム
		const std::string& text, 
		const std::size_t size
	);											
}
