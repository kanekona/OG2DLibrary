#include "Title.h"

Title::Title()
{
	
}
Title::~Title()
{

}
Title* Title::Create()
{
	//new�����̂܂ܕԂ��Ă��邪�A�����łȂɂ����������Ƃ��̂��߂Ɋ֐������Ă���
	return new Title();
}