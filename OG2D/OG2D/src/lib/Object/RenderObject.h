#pragma once
#include "Collision\Collision.h"
/**
*namespace	OG
*@brief	GameObject�Ɋւ���f�[�^
*/
namespace OG
{
	/**
	*enum class Mode
	*@brief	��Ԃ̐ݒ�
	*/
	enum class Mode
	{
		//! �ʏ폈��
		NORMAL,
		//! �|�[�Y�p����
		PAUSE,
		//! �X�V��~
		STOP,
		//! �`��X�V���ɒ�~
		ALLSTOP,
		//! �폜
		KILL,
	};
}
/**
*@brief	�`��I�u�W�F�N�g�֘Aclass
*
*�܂����쒆
*
*/
class RenderObject : private NonCopyable
{
	//! �`�揇
	/*?unsigned int�̃o�C�g���K�v���ǂ����^��ł͂���*/
	unsigned int order;
	// Mode
	OG::Mode mode;
public:
	/**
	*@brief	�`�揈��
	*/
	virtual void Render2D();
	/**
	*@brief	�`�揇�w��
	*���������O�ɕ`�悳���
	*@param[in] unsigned int order �`�揇�l
	*/
	void SetDrawOrder(const unsigned int order);
	/**
	*@brief	�`�揇���擾
	*@return unsigned int �`�揇
	*/
	unsigned int GetDrawOrder() const;
	/**
	*@brief	����̏�Ԃ�Ԃ�
	*@return Mode ���
	*/
	OG::Mode GetMode() const;
	/**
	*@brief	���[�h�m�F
	*@parma[in]	Mode mode ��r�Ώ�
	*@return bool ��r�ΏۂƓ����Ȃ�true
	*/
	bool ModeCheck(const OG::Mode& mode) const;
};