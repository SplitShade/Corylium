#include "EntryPoint.h"
#include "Log.h"
#include <iostream>

namespace Corylium {

	std::function<Application* ()> CreateApplicationCallback = nullptr;

	void SetApplicationInitFunction(std::function<Application* ()> CreateApplication) {
		CreateApplicationCallback = CreateApplication;
	}

	void Initialize()
	{
		Log::Initialize();
		
		Application* app = nullptr;
		if (CreateApplicationCallback != nullptr)
		{
			app = CreateApplicationCallback();
		}
		else
		{
			return;
		}
		std::cout << "Entry Point from Engine!" << std::endl;
		Log::CoreError("This is {}{}{} ({}) error", "o", "n", "e", 1);
		Log::ClientError("This is {}{}{} ({}) error", "t", "w", "o", 2);

		app->Run();
		delete app;
	}
}
