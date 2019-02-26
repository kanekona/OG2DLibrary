#pragma once
/**
*@brief	コピーを禁止するclass
*
*このclassを継承したclassはコピーコンストラクタと代入演算を禁止されます
*/
class NonCopyable
{
	void operator=(const NonCopyable&) = delete;
	NonCopyable(const NonCopyable&) = delete;
protected:
	explicit NonCopyable()
	{

	}
	virtual ~NonCopyable()
	{

	}
};