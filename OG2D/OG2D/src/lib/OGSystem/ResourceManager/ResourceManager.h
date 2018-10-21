
#pragma once
#include "OGSystem\Audio\Sound.h"
#include "OGSystem\Texture\Texture.h"
#include "OGSystem\Shader\shader.h"
/**
*@brief	���\�[�X�𐶐��A����A�Ǘ����s��class
*
*����GameEngine���g�p���Ă���ꍇ�͎����Ő��������
*
*�����ɓo�^���Ă�����̂�Engine�I����������delete�����̂Ŏ�����delete���Ȃ�����
*
*new�����o�^�������͎̂�����DeleteResource�Ă�ŏ����Ă�������
*/
class ResourceManager : private NonCopyable
{
	//! �T�E���h�f�[�^
	std::vector<std::pair<std::string, Sound*>> soundData;
	//! �e�N�X�`���f�[�^
	std::vector<std::pair<std::string, Texture*>> textureData;
	//! �V�F�[�_�[�f�[�^
	std::vector<std::pair<std::string, Shader*>> shaderData;
public:
	/**
	*@brief	���݂���T�E���h�f�[�^�̃|�C���^��o�^����
	*@param[in] string name �o�^��
	*@param[in]	Sound* sound �T�E���h�f�[�^�̃|�C���^
	*/
	void SetSoundData(const std::string& name,Sound* sound);
	/**
	*@brief	�V�����T�E���h�𐶐����f�[�^�ɓo�^����
	*@param[in] string name �o�^��
	*@param[in]	string path �t�@�C���̃p�X
	*@return bool �����ɐ�����true��Ԃ�
	*/
	bool CreateSound(const std::string& name, const std::string& path);
	/**
	*@brief	�o�^����Ă���T�E���h�f�[�^��Ԃ�
	*@param[in] string name�@�o�^��
	*@return Sound* �o�^����Ă���T�E���h��Ԃ�
	*/
	Sound* GetSoundData(const std::string& name);
	/**
	*@brief	���݂���e�N�X�`���f�[�^�̃|�C���^��o�^����
	*@param[in]	string �o�^��
	*@param[in]	Texture* tex �e�N�X�`���f�[�^�̃|�C���^
	*/
	void SetTextureData(const std::string& name,Texture* tex);
	/**
	*@brief	�V�����e�N�X�`���𐶐����f�[�^��o�^����
	*@param[in]	string name �o�^��
	*@param[in]	string path �t�@�C���̃p�X
	*@return bool �����ɐ�����true��Ԃ�
	*/
	bool CreateTexture(const std::string& name, const std::string& path);
	/**
	*@brief	�o�^����Ă���e�N�X�`���f�[�^��Ԃ�
	*@param[in] string name �o�^��
	*@return Sound* �o�^����Ă���e�N�X�`����Ԃ�
	*/
	Texture* GetTextureData(const std::string& name);
	/**
	*@brief	�o�^����Ă���e�N�X�`���f�[�^��j��,delete����
	*@param[in]	string name �o�^��
	*@return bool �폜�ɐ�����true
	*/
	bool DeleteTexture(const std::string& name);
	/**
	*@brief	�o�^����Ă���T�E���h�f�[�^��j��,delete����
	*@param[in]	string name �o�^��
	*@return bool �폜�ɐ�����true
	*/
	bool DeleteSound(const std::string& name);
	/**
	*@brief	�V�����V�F�[�_�[�𐶐����f�[�^��o�^����
	*@param[in] const string& name �o�^��
	*@param[in] const string& path �t�@�C���p�X
	*@return bool �����ɐ�����true��Ԃ�
	*/
	bool CreateShader(const std::string& name, const std::string& path);
	/**
	*@brief	�o�^����Ă���V�F�[�_�[�f�[�^���擾����
	*@param[in] const string& name �o�^��
	*@return Shader* �o�^����Ă���V�F�[�_�[�f�[�^
	*/
	Shader* GetShaderData(const std::string& name);
	/**
	*@brief	destructor 
	*�S�f�[�^��j��,delete����
	*/
	virtual ~ResourceManager();
};