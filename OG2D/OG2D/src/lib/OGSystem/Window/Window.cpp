#include "Window.h"
#include "stb_image.h"
Window::Window()
{
	this->widht = 640;
	this->height = 480;
	this->enableFullScreen = false;
	this->name = "NoName";
	this->enableIcon = false;
	this->isVisualization = false;
	this->window = nullptr;
	this->position = Vec2Int(0, 30);
}
Window::Window(const int wi, const int he, const char* windowname, const bool screen,const Vec2Int& pos)
	:widht(wi)
	, height(he)
	, name(windowname)
	, enableFullScreen(screen)
	, position(pos)
{
	this->window = glfwCreateWindow(this->widht, this->height, this->name, this->enableFullScreen ? glfwGetPrimaryMonitor() : NULL, NULL);
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

bool Window::Create(const int wi, const int he, char* windowname, const bool screen,const Vec2Int& pos)
{
	this->widht = wi;
	this->height = he;
	this->name = windowname;
	this->enableFullScreen = screen;
	this->position = pos;
	this->window = glfwCreateWindow(this->widht, this->height, this->name, this->enableFullScreen ? glfwGetPrimaryMonitor() : NULL, this->window ? this->window : NULL);
	if (!this->window) {
		glfwTerminate();
		return false;
	}
	glfwSetWindowPos(this->window, this->position.x, this->position.y);
	return true;
}
bool Window::Create()
{
	this->window = glfwCreateWindow(this->widht, this->height, this->name, this->enableFullScreen ? glfwGetPrimaryMonitor() : NULL, this->window ? this->window : NULL);
	if (!this->window) {
		glfwTerminate();
		return false;
	}
	glfwSetWindowPos(this->window, this->position.x, this->position.y);
	return true;
}
bool Window::Create(const WindowParameter& parameter)
{
	this->widht = parameter.size.x;
	this->height = parameter.size.y;
	this->name = parameter.name;
	this->enableFullScreen = parameter.enableFullScreen;
	this->position = parameter.position;
	this->window = glfwCreateWindow(this->widht, this->height, this->name, this->enableFullScreen ? glfwGetPrimaryMonitor() : NULL, this->window ? this->window : NULL);
	if (!this->window) {
		glfwTerminate();
		return false;
	}
	glfwSetWindowPos(this->window, (int)this->position.x, (int)this->position.y);
	return true;
}
void Window::SetIcon(const std::string& path)
{
	//stbimageを使って画像を読み込む
	image[0].pixels = stbi_load(path.c_str(), &image[0].width, &image[0].height, 0, 4);
	//glfwに設定したいWindowとアイコンにしたい画像データと個数を送る
	glfwSetWindowIcon(this->window, 1, image);
	//データの解放
	stbi_image_free(image[0].pixels);
}
void Window::Limits()
{
	//Windowのサイズを固定化させる
	glfwSetWindowSizeLimits(this->window, this->widht, this->height, this->widht, this->height);
	//windowのアスペクト比を固定させる
	glfwSetWindowAspectRatio(this->window, 16, 9);
	//windowのサイズを変更する(固定化されている場合変更はできない)
	//glfwSetWindowSize(this->window, 1920, 1080);
}
void Window::Limits(const int w,const int h)
{
	//Windowのサイズを固定化させる
	glfwSetWindowSizeLimits(this->window, w, h, w, h);
	//windowのアスペクト比を固定させる
	glfwSetWindowAspectRatio(this->window, 16, 9);
	//windowのサイズを変更する(固定化されている場合変更はできない)
	//glfwSetWindowSize(this->window, 1920, 1080);
}
void Window::Enable()
{
	if (this->enableIcon)
	{
		//Icon化されたwindowを元に戻す
		glfwRestoreWindow(this->window);
		this->enableIcon = false;
	}
	else
	{
		//windowをIcon化させる
		glfwIconifyWindow(this->window);
		this->enableIcon = true;
	}
}

void Window::Visualization()
{
	if (this->isVisualization)
	{
		//隠れたwindowを元に戻す
		glfwShowWindow(this->window);
		this->isVisualization = false;
	}
	else
	{
		//windowを隠す
		glfwHideWindow(this->window);
		this->isVisualization = true;
	}
}

void Window::InMouseMode(const bool index)
{
	glfwSetInputMode(this->window, GLFW_CURSOR, index ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN);
}
Vec2Int Window::GetSize() const
{
	int w, h;
	glfwGetWindowSize(this->window, &w, &h);
	return Vec2Int(w, h);
}
Vec2Int Window::GetPos() const
{
	int x, y;
	glfwGetWindowPos(this->window, &x, &y);
	return Vec2Int(x, y);
}
void Window::CreatePosition(const Vec2Int& pos)
{
	this->position = pos;
}
GLFWwindow* Window::GetFWWindow() const
{
	return this->window;
}
void Window::SetPos(const Vec2Int& pos)
{
	glfwSetWindowPos(this->window, pos.x, pos.y);
}
void Window::SetPos(const int x, const int y)
{
	glfwSetWindowPos(this->window, x, y);
}
void Window::SetSize(const Vec2Int& size)
{
	this->Limits(size.x, size.y);
	glfwSetWindowSize(this->window, size.x, size.y);
}
void Window::SetSize(const int w, const int h)
{
	this->Limits(w, h);
	glfwSetWindowSize(this->window, w, h);
}
void Window::ChengeTitle(const char* windowname)
{
	glfwSetWindowTitle(this->window, name);
}
void Window::ChangeMode(const int x, const int y, const int w, const int h, const bool flag)
{
	this->SetPos(x, y);
	this->SetSize(w, h);
	glfwSetWindowMonitor(this->window, flag ? glfwGetPrimaryMonitor() : NULL, x, y, w, h, GLFW_DONT_CARE);
}
void Window::ChangeMode(const Vec2Int& pos, const Vec2Int& size, const bool flag)
{
	this->ChangeMode(pos.x, pos.y, size.x, size.y, flag);
}

WindowParameter::WindowParameter(const Vec2Int& p, const Vec2Int& s, const char* n, const bool f)
{
	this->position = p;
	this->size = s;
	this->name = n;
	this->enableFullScreen = f;
}