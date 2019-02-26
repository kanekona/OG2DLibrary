#include "System\System_.h"
#include "Engine.h"
#include "Input\Input.h"
#include "Random\Random.h"
#include "ResourceManager\ResourceManager.h"
Engine::Engine()
{
	//OpenGL,OpenFW Initialize
	GLFWInitialize();
	//GameFramework‚Ì¶¬
	framework = Framework::Create(&enable);
	//Get Framework Window Address
	window = framework->GetWindow();
	//OutsideLibrary Initialize
	OutsideLibraryInitialize();
	//AudioDevice‚Ìİ’è
	audiodevice = new Audio();
	//ResourceManaget‚Ì¶¬
	ResourceManager::Create();
	//Input‚Ì¶¬
	Input::Create(framework->GetWindow()->GetFWWindow());
}
Engine::~Engine()
{
	//Input‚Ì”jŠü
	Input::Destroy();
	//ResourceManager‚Ì”jŠü
	ResourceManager::Destroy();
	//AudioDevice‚Ì”jŠü
	OG::Destroy<Audio>(audiodevice);
	//GameFramework‚Ì”jŠü
	Framework::Destroy();
	//GLFWI—¹ˆ—
	glfwTerminate();
}
void Engine::GLFWInitialize()
{
	//GLFW Initialize
	if (!glfwInit())
	{
		throw ERROR_GLFE_INIT;
	}
	//OpenGL Version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
}
void Engine::OutsideLibraryInitialize()
{
	//User Window
	glfwMakeContextCurrent(window->GetFWWindow());
	//Timeing Specification Double Buffer
	glfwSwapInterval(1);
#if defined(_MSC_VER)
	//GLEW Initialize
	if (glewInit() != GLEW_OK)
	{
		//Destroy Window and Cursor
		glfwTerminate();
		throw ERROR_GLEW_INIT;
	}
#endif
	//Rendering Range
	glViewport(0, 0, (GLsizei)window->GetSize().x, (GLsizei)window->GetSize().y);
	//Matrix Initialize
	glLoadIdentity();
	//Specification Normal Vector
	glEnable(GL_NORMALIZE);
	//Back Color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//Random Seed Initialize
	Random::Init();
}
bool Engine::SystemUpdate()
{
	if (fps.FrameCheck())
	{
		//Double Buffer
		glfwSwapBuffers(window->GetFWWindow());
		//Device Update
		glfwPollEvents();
		//Device Class Update
		Input::Get()->Update();
		//Matrix Mode Change
		glMatrixMode(GL_MODELVIEW);
		//Clear Buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//FragmentColor to Color Buffer Brend
		glEnable(GL_BLEND);
		//Calculation Pixel
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//Framework Update
		framework->Update();
		//Delete Check
		if (enable)
		{
			glfwDestroyWindow(window->GetFWWindow());
			return false;
		}
	}
	return !glfwWindowShouldClose(window->GetFWWindow());
}