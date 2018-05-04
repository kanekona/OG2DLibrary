#include "Window.h"
#include "stb_image.h"
Window::Window()
{
	this->_widht = 640;
	this->_height = 480;
	this->_Screen = false;
	this->_Name = "NoName";
	this->isIcon = false;
	this->isVisualization = false;
}
Window::Window(int wi, int he, char* name, bool screen,Vec2& pos)
	:_widht(wi)
	, _height(he)
	, _Name(name)
	, _Screen(screen)
	, position(pos)
{
	if (_Screen) {
		window = glfwCreateWindow(_widht, _height, _Name, glfwGetPrimaryMonitor(), NULL);
	}
	else
	{
		window = glfwCreateWindow(_widht, _height, _Name, NULL, NULL);
	}
	if (!window) {
		glfwTerminate();
		return;
	}
	glfwSetWindowPos(this->window, this->position.x, this->position.y);
}
Window::~Window()
{
	glfwSetWindowIcon(this->window, 0, NULL);
}

Window::SP Window::Create(int wi, int he, char* name, bool screen,Vec2& pos)
{
	return Window::SP(new Window(wi, he, name, screen, pos));
}

void Window::createWindow(int wi, int he, char* name, bool screen,Vec2& pos)
{
	this->_widht = wi;
	this->_height = he;
	this->_Name = name;
	this->_Screen = screen;
	this->position = pos;
	if (this->_Screen) {
		this->window = glfwCreateWindow(this->_widht, this->_height, this->_Name, glfwGetPrimaryMonitor(), NULL);
	}
	else
	{
		this->window = glfwCreateWindow(this->_widht, this->_height, this->_Name, NULL, NULL);
	}
	if (!this->window) {
		glfwTerminate();
		return;
	}
	glfwSetWindowPos(this->window, this->position.x, this->position.y);
}
void Window::setIcon(std::string& path_)
{
	//stbimage���g���ĉ摜��ǂݍ���
	image[0].pixels = stbi_load(path_.c_str(), &image[0].width, &image[0].height, 0, 4);
	//glfw�ɐݒ肵����Window�ƃA�C�R���ɂ������摜�f�[�^�ƌ��𑗂�
	glfwSetWindowIcon(this->window, 1, image);
	//�f�[�^�̉��
	stbi_image_free(image[0].pixels);
}
void Window::LimitsWindow()
{
	//Window�̃T�C�Y���Œ艻������
	glfwSetWindowSizeLimits(this->window, this->_widht, this->_height, this->_widht, this->_height);
	//window�̃A�X�y�N�g����Œ肳����
	glfwSetWindowAspectRatio(this->window, 16, 9);
	//window�̃T�C�Y��ύX����(�Œ艻����Ă���ꍇ�ύX�͂ł��Ȃ�)
	//glfwSetWindowSize(this->window, 1920, 1080);
}
void Window::WindowIcon()
{
	if (this->isIcon)
	{
		//Icon�����ꂽwindow�����ɖ߂�
		glfwRestoreWindow(this->window);
		this->isIcon = false;
	}
	else
	{
		//window��Icon��������
		glfwIconifyWindow(this->window);
		this->isIcon = true;
	}
}

void Window::Visualization()
{
	if (this->isVisualization)
	{
		//�B�ꂽwindow�����ɖ߂�
		glfwShowWindow(this->window);
		this->isVisualization = false;
	}
	else
	{
		//window���B��
		glfwHideWindow(this->window);
		this->isVisualization = true;
	}
}

void Window::InMouseMode(const bool index)
{
	if (index)
	{
		glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
	else
	{
		glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	}
}
Vec2 Window::GetSize() const
{
	int w, h;
	glfwGetWindowSize(this->window, &w, &h);
	return Vec2(w, h);
}
Vec2 Window::GetPos() const
{
	int x, y;
	glfwGetWindowPos(this->window, &x, &y);
	return Vec2(x, y);
}
void Window::SetWindowPos(Vec2& pos)
{
	this->position = pos;
}