#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Pretzel
{
	class PRETZEL_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* createApplication();
}

