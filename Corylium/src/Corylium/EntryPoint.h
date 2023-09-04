#pragma once
#ifdef CRLY_PLATFORM_WINDOWS

extern Corylium::Application* Corylium::CreateApplication();

int main(int argc, char** argv) {
	Corylium::Application* app = Corylium::CreateApplication();
	//printf("Entry Point from Engine\n");
	app->Run();
	delete app;
	return 0;
}

#endif