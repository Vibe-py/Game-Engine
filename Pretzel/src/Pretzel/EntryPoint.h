#pragma once

#ifdef PZ_PLATFORM_WINDOWS

extern Pretzel::Application* Pretzel::createApplication();

int main(int argc, int** argv)
{
	Pretzel::Log::Init();
	PZ_CORE_WARN("COS(OMAK) PRETZEL");

	auto app = Pretzel::createApplication();
	app->Run();
	delete app;
}

#endif