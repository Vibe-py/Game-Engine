#include <Pretzel.h>

class Sandbox : public Pretzel::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Pretzel::Application* Pretzel::createApplication()
{
	return new Sandbox();
}