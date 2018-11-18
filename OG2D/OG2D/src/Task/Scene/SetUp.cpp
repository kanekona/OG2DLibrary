#include "SetUp.h"
#include "Event\WindowsEvent\WindowsEvent.h"
SetUp::SetUp()
{
	this->mode = Mode::NON;	
}

SetUp::~SetUp()
{

}

void SetUp::Update()
{
	switch (this->mode)
	{
	case Mode::LOADFILE:
	{
		LOADFILE* lf = new LOADFILE();
		delete lf;
		this->mode = Mode::NON;
	}
		break;
	case Mode::NON:
		if (ge->in->down(In::B1))
		{
			this->mode = Mode::LOADFILE;
		}
		break;
	}
}

LOADFILE::LOADFILE()
{
	WindowsEvent* we = new WindowsEvent;
	we->SetLoadPath(".png");
	we->SetNotLoadFileName("Žg—p—á");
	std::vector<std::string> v = we->ResourceFileNameLoad("data\\image\\kiritan");
	for (int i = 0; i < v.size(); ++i)
	{
		v[i] = v[i].substr(11, v[i].size());
		v[i] = "Texture>" + v[i] + ",kiri" + std::to_string(i);
	}
	OG::FileCreate("./data/event/kiritanFile.og", v);
	delete we;
}

LOADFILE::~LOADFILE()
{

}