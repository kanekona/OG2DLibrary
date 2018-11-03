
#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
/**
*@brief	Easing������class
*
*�e�ڍׂ�Easing�\���m�F
*/
class Easing
{
private:
	//! TimeCount
	float cnt;
	//! EnablePlay
	bool toplay = false;
	//! StartValue
	float start;
	//! EndValue
	float end;
public:
	/**
	*enum class Name
	*@brief	EasingName
	*/
	enum class Name
	{
		Back, Bounce, Circ, Cubic, Elastic, Expo, Linear, Quad, Quart, Quint, Sine
	};
	/**
	*enum class Mode
	*@brief	EasingMode
	*/
	enum class Mode
	{
		In, Out, InOut
	};
	/**
	*@brief	�C�[�W���O�p�J�E���^
	*@param[in]	float duration �ݒ�^�C��
	*@return ���݃^�C��
	*/
	float Time(const float duration)
	{
		if (cnt <= duration)
		{
			cnt += 0.1f;
		}
		if (cnt >= duration)
		{
			this->toplay = false;
		}
		return cnt;
	}
	/**
	*@brief	���s�����擾
	*@return bool true ���s��
	*/
	bool IsPlay() const
	{
		return this->toplay;
	}
	/**
	*@brief	�^�C��������
	*/
	void ResetTime()
	{
		this->cnt = 0;
		this->toplay = true;
		this->start = 0;
		this->end = 0;
	}
	/**
	*@brief	constructor
	*/
	Easing() { this->ResetTime(); };
	/**
	*@brief	�J�n�ƏI���n�_��o�^
	*@param[in] float startValue StartValue
	*@param[in] float endValue EndValue
	*/
	void Set(const float startValue, const float endValue)
	{
		this->start = startValue;
		this->end = endValue;
	}

	/**
	*@brief	�J�n�n�_���擾
	*@return float StartValue
	*/
	float GetStartValue() const
	{
		return this->start;
	}
	/**
	*@brief	�I���n�_���擾
	*@return float EndValue
	*/
	float GetEndValue() const
	{
		return this->end;
	}

	//t = ���� d = �n�_ c = �I�_-�n�_ d = �o�ߎ���
	class Linear
	{
	public:
		float None(float t, float b, float c, float d)
		{
			return c * t / d + b;
		}
		float In(float t, float b, float c, float d)
		{
			return c * t / d + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return c * t / d + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			return c * t / d + b;
		}
	}linear;

	//t = ���� d = �n�_ c = �I�_-�n�_ d = �o�ߎ���
	class Back
	{
	public:
		float In(float t, float b, float c, float d)
		{
			float s = 1.70158f;
			float postFix = t /= d;
			return c * (postFix)*t*((s + 1)*t - s) + b;
		}
		float Out(float t, float b, float c, float d)
		{

			float s = 1.70158f;

			return c * ((t = t / d - 1)*t*((s + 1)*t + s) + 1) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			float s = 1.70158f;
			if ((t /= d / 2) < 1) return c / 2 * (t*t*(((s *= (1.525f)) + 1)*t - s)) + b;
			float postFix = t -= 2;
			return c / 2 * ((postFix)*t*(((s *= (1.525f)) + 1)*t + s) + 2) + b;
		}
	}back;


	//t = ���� d = �n�_ c = �I�_-�n�_ d = �o�ߎ���
	class Bounce
	{
	public:
		float Out(float t, float b, float c, float d)
		{

			if ((t /= d) < (1 / 2.75f))
			{
				return c * (7.5625f*t*t) + b;
			}
			else if (t < (2 / 2.75f))
			{
				float postFix = t -= (1.5f / 2.75f);
				return c * (7.5625f*(postFix)*t + .75f) + b;
			}
			else if (t < (2.5 / 2.75))
			{
				float postFix = t -= (2.25f / 2.75f);
				return c * (7.5625f*(postFix)*t + .9375f) + b;
			}
			else
			{
				float postFix = t -= (2.625f / 2.75f);
				return c * (7.5625f*(postFix)*t + .984375f) + b;
			}
		}
		float In(float t, float b, float c, float d)
		{
			return c - Out(d - t, 0, c, d) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if (t < d / 2) return In(t * 2, 0, c, d) * .5f + b;
			else return Out(t * 2 - d, 0, c, d) * .5f + c * .5f + b;
		}
	}bounce;

	//t = ���� d = �n�_ c = �I�_-�n�_ d = �o�ߎ���
	class Circ
	{
	public:
		float In(float t, float b, float c, float d)	//�o�O����
		{
			return -c * static_cast<float>((sqrt(1 - (t /= d)*t) - 1)) + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return c * static_cast<float>(sqrt(1 - (t = t / d - 1)*t)) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return -c / 2 * static_cast<float>((sqrt(1 - t * t) - 1)) + b;
			return c / 2 * static_cast<float>((sqrt(1 - t * (t -= 2)) + 1)) + b;
		}
	}circ;

	//t = ���� d = �n�_ c = �I�_-�n�_ d = �o�ߎ���
	class Cubic
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return c * (t /= d)*t*t + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return c * ((t = t / d - 1)*t*t + 1) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return c / 2 * t*t*t + b;
			return c / 2 * ((t -= 2)*t*t + 2) + b;
		}
	}cubic;

	//t = ���� d = �n�_ c = �I�_-�n�_ d = �o�ߎ���
	class Elastic
	{
	public:
		float In(float t, float b, float c, float d)
		{
			if (t == 0) return b;  if ((t /= d) == 1) return b + c;
			float p = d * .3f;
			float a = c;
			float s = p / 4;
			float postFix = static_cast<float>(a*pow(2, 10 * (t -= 1)));
			return -static_cast<float>(postFix * sin((t*d - s)*(2 * (M_PI)) / p)) + b;
		}

		float Out(float t, float b, float c, float d)
		{
			if (t == 0) return b;  if ((t /= d) == 1) return b + c;
			float p = d * .3f;
			float a = c;
			float s = p / 4;
			return (static_cast<float>(a*pow(2, -10 * t) * sin((t*d - s)*(2 * static_cast<float>(M_PI)) / p) + c + b));
		}

		float InOut(float t, float b, float c, float d)
		{
			if (t == 0) return b;  if ((t /= d / 2) == 2) return b + c;
			float p = d * (.3f*1.5f);
			float a = c;
			float s = p / 4;

			if (t < 1) {
				float postFix = static_cast<float>(a*pow(2, 10 * (t -= 1)));
				return -.5f*static_cast<float>((postFix* sin((t*d - s)*(2 * (M_PI)) / p))) + b;
			}
			float postFix = static_cast<float>(a*pow(2, -10 * (t -= 1)));
			return static_cast<float>(postFix * sin((t*d - s)*(2 * static_cast<float>(M_PI)) / p)*.5f + c + b);
		}
	}elastic;

	//t = ���� d = �n�_ c = �I�_-�n�_ d = �o�ߎ���
	class Expo
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return (t == 0) ? b : c * static_cast<float>(pow(2, 10 * (t / d - 1)) + b);
		}
		float Out(float t, float b, float c, float d)
		{
			return (t == d) ? b + c : c * (static_cast<float>(-pow(2, -10 * t / d) + 1)) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if (t == 0) return b;
			if (t == d) return b + c;
			if ((t /= d / 2) < 1) return c / 2 * static_cast<float>(pow(2, 10 * (t - 1))) + b;
			return c / 2 * (static_cast<float>(-pow(2, -10 * --t) + 2)) + b;
		}
	}expo;

	//t = ���� d = �n�_ c = �I�_-�n�_ d = �o�ߎ���	
	class Quad
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return c * (t /= d)*t + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return -c * (t /= d)*(t - 2) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return ((c / 2)*(t*t)) + b;
			return -c / 2 * (((t - 2)*(--t)) - 1) + b;
		}
	}quad;

	//t = ���� d = �n�_ c = �I�_-�n�_ d = �o�ߎ���
	class Quart
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return c * (t /= d)*t*t*t + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return -c * ((t = t / d - 1)*t*t*t - 1) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return c / 2 * t*t*t*t + b;
			return -c / 2 * ((t -= 2)*t*t*t - 2) + b;
		}
	}quart;

	//t = ���� d = �n�_ c = �I�_-�n�_ d = �o�ߎ���
	class Quint
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return c * (t /= d)*t*t*t*t + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return c * ((t = t / d - 1)*t*t*t*t + 1) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return c / 2 * t*t*t*t*t + b;
			return c / 2 * ((t -= 2)*t*t*t*t + 2) + b;
		}
	}quint;

	//t = ���� d = �n�_ c = �I�_-�n�_ d = �o�ߎ���
	class Sine
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return -c * static_cast<float>(cos(t / d * (M_PI / 2))) + c + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return c * static_cast<float>(sin(t / d * (M_PI / 2))) + b;
		}

		float InOut(float t, float b, float c, float d)
		{
			return -c / 2 * static_cast<float>((cos(M_PI*t / d) - 1)) + b;
		}
	}sine;

};