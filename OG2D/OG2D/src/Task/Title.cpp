#include "Title.h"

Title::Title()
{
	
}
Title::~Title()
{

}
Title* Title::Create()
{
	//newをそのまま返しているが、ここでなにか書きたいときのために関数化している
	return new Title();
}