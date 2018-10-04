/**
*���\�[�X�𐶐��A����A�Ǘ����s��class
*����GameEngine���g�p���Ă���ꍇ�͎����Ő��������
*�����ɓo�^���Ă�����͎̂�����delete�����̂Ŏ�����delete���Ȃ�����
*/
#pragma once
#include "OGSystem\Audio\Sound.h"
#include "OGSystem\Texture\Texture.h"

class ResourceManager : private NonCopyable
{
	//! �T�E���h�f�[�^
	std::vector<std::pair<std::string, Sound*>> soundData;
	//! �e�N�X�`���f�[�^
	std::vector<std::pair<std::string, Texture*>> textureData;
public:
	/**
	*@brief	:���݂���T�E���h�f�[�^�̃|�C���^��o�^����
	*@param :string name �o�^��
	*@param	:Sound* sound �T�E���h�f�[�^�̃|�C���^
	*/
	void SetSoundData(const std::string& name,Sound* sound);
	/**
	*@brief	:�V�����T�E���h�𐶐����f�[�^�ɓo�^����
	*@param :string name �o�^��
	*@param	:string path �t�@�C���̃p�X
	*@return:bool �����ɐ�����true��Ԃ�
	*/
	bool CreateSound(const std::string& name, const std::string& path);
	/**
	*@brief	:�o�^����Ă���T�E���h�f�[�^��Ԃ�
	*@param :string name�@�o�^��
	*@return:Sound* �o�^����Ă���T�E���h��Ԃ�
	*/
	Sound* GetSoundData(const std::string& name);
	/**
	*@brief	:���݂���e�N�X�`���f�[�^�̃|�C���^��o�^����
	*@param	:string �o�^��
	*@param	:Texture* tex �e�N�X�`���f�[�^�̃|�C���^
	*/
	void SetTextureData(const std::string& name,Texture* tex);
	/**
	*@brief	:�V�����e�N�X�`���𐶐����f�[�^��o�^����
	*@param	:string name �o�^��
	*@param	:string path �t�@�C���̃p�X
	*@return:bool �����ɐ�����true��Ԃ�
	*/
	bool CreateTexture(const std::string& name, const std::string& path);
	/**
	*@brief	:�o�^����Ă���e�N�X�`���f�[�^��Ԃ�
	*@param :string name �o�^��
	*@return:Sound* �o�^����Ă���e�N�X�`����Ԃ�
	*/
	Texture* GetTextureData(const std::string& name);
	/**
	*@brief	:�o�^����Ă���e�N�X�`���f�[�^��j��,delete����
	*@param	:string name �o�^��
	*@return:bool �폜�ɐ�����true
	*/
	bool DeleteTexture(const std::string& name);
	/**
	*@brief	:�o�^����Ă���T�E���h�f�[�^��j��,delete����
	*@param	:string name �o�^��
	*@return:bool �폜�ɐ�����true
	*/
	bool DeleteSound(const std::string& name);
	/**
	*@brief	:destructor �S�f�[�^��j��,delete����
	*/
	virtual ~ResourceManager();
};