#include "Event.h"
#include "ResourceLoad\ResourceLoad.h"
#include "WindowEvent\WindowEvent.h"
EventTask::EventTask()
{

}
EventTask::~EventTask()
{

}
bool EventTask::Load(const Event& eventType, const std::string& path)
{
	//�������̃t�@�C�����ق��ŊJ����Ă���Ȃ����
	if (this->ifs.is_open())
	{
		this->ifs.close();
	}
	//�t�@�C�����J��
	this->ifs.open(path);
	//���݂��Ȃ��ꍇ�I������
	if (!this->ifs)
	{
		return false;
	}
	//�ǂݍ��񂾃t�@�C�����w�肵����ނ�Event�Ŏ��s����
	switch (eventType)
	{
	case Event::RESOURCE_LOAD:
	{
		//constructor�ŏ������I���̂Ő�������delete����
		ResourceLoad* rl = new ResourceLoad(this->ifs);
		delete rl;
	}
	break;
		break;
	}
	return true;
}