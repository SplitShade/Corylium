#include "crlypch.h"
#include "EntryPoint.h"
#include "Log.h"

namespace Corylium {

	void CreateApplication(Application& DerivedApplication) {
		Init(DerivedApplication);
	}

	void Init(Application& DerivedApplication)
	{
		std::string_view appName = DerivedApplication.GetName();
		Log::Init(appName);
		Log::CoreInfo("Entrypoint from Engine");

		if (appName == Corylium::Application::GetDefaultAppName())
		{
			Log::CoreInfo("No application name provided when initializing engine. Using default");
		}

		Log::CoreError("This is {}{}{} ({}) error", "o", "n", "e", 1);

		//DerivedApplication.Run();
	}
}
