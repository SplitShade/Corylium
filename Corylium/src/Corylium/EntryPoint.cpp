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
		Log::CoreError("This is %s%s%s%d error", "o", "n", "e", 1);
		Log::CoreError();
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
		app->Run();
		delete app;
	}
}
