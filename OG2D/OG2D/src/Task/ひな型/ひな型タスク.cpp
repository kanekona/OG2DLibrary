#include "�ЂȌ`�^�X�N.h"
//�ʃ^�X�N��ʃI�u�W�F�N�g�𐶐�����ꍇ�����ɂ���class�̏����ꂽh���C���N���[�h����
#include "�ЂȌ`�I�u�W�F�N�g.h"

bool �u��������class���v::Initialize()
{
	//-----------------------------
	//�������ɏ������鏉�����������L�q
	//-----------------------------
	this->taskName = "";			//�������Ɏg�����߂̖���o�^����
	__super::Init(taskName);		//TaskObject���̏������s��
	//������
	auto �ЂȌ` = �u�ЂȌ`�I�u�W�F�N�g�v::Create(true);
	return true;
}

void �u��������class���v::UpDate()
{
	//--------------------
	//�X�V���ɍs���������L�q
	//--------------------
	if(OGge->in->key.down(In::X))
	{
		//�����������ꍇ��Kill���g��
		this->Kill();
	}
}

void �u��������class���v::Render2D()
{
	//--------------------
	//�`�掞�ɍs���������L�q
	//--------------------
}
bool �u��������class���v::Finalize()
{
	//-----------------------------------------
	//���̃I�u�W�F�N�g�����ł���Ƃ��ɍs���������L�q
	//-----------------------------------------
	//���̃^�X�N����邩���A�v���P�[�V�������I���\�肩�ǂ���
	if (this->GetNextTask() && !OGge->GetDeleteEngine())
	{
		
	}
	return true;
}
//----------------------------
//�������牺��class���̂ݕύX����
//�ق��͕ύX���Ȃ�����
//----------------------------
�u��������class���v::�u��������class���v()
{
	
}

�u��������class���v::~�u��������class���v()
{
	this->Finalize();
}

�u��������class���v::SP �u��������class���v::Create(bool flag_)
{

	�u��������class���v::SP to = �u��������class���v::SP(new �u��������class���v());
	if (to)
	{
		to->me = to;
		if (flag_)
		{
			OGge->SetTaskObject(to);
		}
		if (!to->Initialize())
		{
			to->Kill();
		}
		return to;
	}
	return nullptr;
}