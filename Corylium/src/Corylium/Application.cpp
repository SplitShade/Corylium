#include "Application.h"

namespace Corylium {

	Application::Application()
	{
	}

	Application::Application(std::string_view Name)
		:_name{Name}
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (true);
	}

	std::string Application::GetName() const
	{
		return _name;
	}
}