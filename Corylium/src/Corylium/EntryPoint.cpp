#include "EntryPoint.h"
#include "Log.h"
#include <iostream>

namespace Corylium {

	void CreateApplication(Application& DerivedApplication) {
		Initialize(DerivedApplication);
	}

	void Initialize(Application& DerivedApplication)
	{
		std::cout << "Entry Point from Engine!" << std::endl;
		std::string appName = DerivedApplication.GetName();
		Log::Initialize(appName);

		if (appName == "APP")
		{
			Log::CoreInfo("No application name provided when initializing engine. Using default");
		}

		Log::CoreError("This is {}{}{} ({}) error", "o", "n", "e", 1);

		//DerivedApplication.Run();
	}
}
