
import Corylium;
#include "Core.h"
#include "EntryPoint.h"

class Sandbox : public Corylium::Application {
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Corylium::Application* Corylium::CreateApplication()
{
	return new Sandbox();
}