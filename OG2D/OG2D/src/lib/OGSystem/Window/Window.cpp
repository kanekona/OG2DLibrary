#include "Window.h"
#include "stb_image.h"
Window::Window()
{
	this->widht = 640;
	this->height = 480;
	this->_screen = false;
	this->_name = "NoName";
	this->enableIcon = false;
	this->isVisualization = false;
	this->window = nullptr;
}
Window::Window(const int wi, const int he, const char* name, const bool screen,const Vec2& pos)
	:widht(wi)
	, height(he)
	, _name(name)
	, _screen(screen)
	, position(pos)
{
	this->window = glfwCreateWindow(this->widht, this->height, this->_name, this->_screen ? glfwGetPrimaryMonitor() : NULL, NULL);
	if (!window) {
		glfwTerminate();
		return;
	}
	glfwSetWindowPos(this->window, (int)this->position.x, (int)this->position.y);
}
Window::~Window()
{
	glfwSetWindowIcon(this->window, 0, NULL);
}

bool Window::createWindow(const int wi, const int he, char* name, const bool screen,const Vec2& pos)
{
	this->widht = wi;
	this->height = he;
	this->_name = name;
	this->_screen = screen;
	this->position = pos;
	this->window = glfwCreateWindow(this->widht, this->height, this->_name, this->_screen ? glfwGetPrimaryMonitor() : NULL, this->window ? this->window : NULL);
	if (!this->window) {
		glfwTerminate();
		return false;
	}
	glfwSetWindowPos(this->window, (int)this->position.x, (int)this->position.y);
	return true;
}
void Window::SetIcon(const std::string& path_)
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
	glfwSetWindowSizeLimits(this->window, this->widht, this->height, this->widht, this->height);
	//window�̃A�X�y�N�g����Œ肳����
	glfwSetWindowAspectRatio(this->window, 16, 9);
	//window�̃T�C�Y��ύX����(�Œ艻����Ă���ꍇ�ύX�͂ł��Ȃ�)
	//glfwSetWindowSize(this->window, 1920, 1080);
}
void Window::LimitsWindow(const int w,const int h)
{
	//Window�̃T�C�Y���Œ艻������
	glfwSetWindowSizeLimits(this->window, w, h, w, h);
	//window�̃A�X�y�N�g����Œ肳����
	glfwSetWindowAspectRatio(this->window, 16, 9);
	//window�̃T�C�Y��ύX����(�Œ艻����Ă���ꍇ�ύX�͂ł��Ȃ�)
	//glfwSetWindowSize(this->window, 1920, 1080);
}
void Window::WindowIcon()
{
	if (this->enableIcon)
	{
		//Icon�����ꂽwindow�����ɖ߂�
		glfwRestoreWindow(this->window);
		this->enableIcon = false;
	}
	else
	{
		//window��Icon��������
		glfwIconifyWindow(this->window);
		this->enableIcon = true;
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
	glfwSetInputMode(this->window, GLFW_CURSOR, index ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN);
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
void Window::SetWindowPos(const Vec2& pos)
{
	this->position = pos;
}
GLFWwindow* Window::GetWindow() const
{
	return this->window;
}
void Window::SetPos(const Vec2& pos)
{
	glfwSetWindowPos(this->window, (int)pos.x, (int)pos.y);
}
void Window::SetPos(const int x, const int y)
{
	glfwSetWindowPos(this->window, x, y);
}
void Window::SetSize(const Vec2& size)
{
	this->LimitsWindow((int)size.x, (int)size.y);
	glfwSetWindowSize(this->window, (int)size.x, (int)size.y);
}
void Window::SetSize(const int w, const int h)
{
	this->LimitsWindow(w, h);
	glfwSetWindowSize(this->window, w, h);
}
void Window::ChengeTitle(const char* name)
{
	glfwSetWindowTitle(this->window, name);
}
void Window::ChengeWindow(const int x, const int y, const int w, const int h, const bool flag)
{
	this->SetPos(x, y);
	this->SetSize(w, h);
	glfwSetWindowMonitor(this->window, flag ? glfwGetPrimaryMonitor() : NULL, x, y, w, h, GLFW_DONT_CARE);
}
void Window::ChengeWindow(const Vec2& pos, const Vec2& size, const bool flag)
{
	this->ChengeWindow((int)pos.x, (int)pos.y, (int)size.x, (int)size.y, flag);
}