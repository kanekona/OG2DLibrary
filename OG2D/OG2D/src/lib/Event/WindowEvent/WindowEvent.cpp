#include "WindowEvent.h"

WindowEvent::WindowEvent(std::ifstream& ifs,int* x,int* y)
{
	std::string lineText;
	while (std::getline(ifs, lineText))
	{
		//'/'‚ª“ª‚É‚Â‚¢‚Ä‚¢‚é‚à‚Ì‚Í“Ç‚İ‚Ü‚È‚¢
		if (lineText.at(0) == '/')
		{
			continue;
		}
		std::string::size_type t;
		while ((t = lineText.find_first_of("(,);")) != std::string::npos)
		{
			lineText[t] = ' ';
		}
		std::stringstream ss;
		ss << lineText;

		int size_x, size_y;
		ss >> size_x >> size_y;
		*x = size_x;
		*y = size_y;
	}
}
WindowEvent::~WindowEvent()
{

}