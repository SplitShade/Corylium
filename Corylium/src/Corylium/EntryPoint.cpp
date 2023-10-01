module EntryPoint;
import Application;
import std;

namespace Corylium {

	std::function<Application* ()> CreateApplicationCallback = nullptr;

	void SetApplicationInitFunction(std::function<Application* ()> CreateApplication) {
		CreateApplicationCallback = CreateApplication;
	}

	void Initialize()
	{
		Application* app = nullptr;
		if (CreateApplicationCallback != nullptr) {
			app = CreateApplicationCallback();
		}
		else {
			return;
		}
		std::cout << "Entry Point from Engine!" << std::endl;
		app->Run();
		delete app;
	}
}
