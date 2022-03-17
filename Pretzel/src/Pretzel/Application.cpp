#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Pretzel
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1920, 1080);
		PZ_TRACE(e);
		while (true);
	}
}