#include "Corylium.h"

static constexpr std::string_view APP_NAME = "SandboxApp";

class Sandbox : public Corylium::Application {
public:
	Sandbox()
		: Corylium::Application()
	{
	}

	Sandbox(std::string_view Name)
		: Corylium::Application(Name)
	{
	}

	~Sandbox()
	{
	}
};


int main(int argc, char** argv) {
	std::unique_ptr<Sandbox> app = std::make_unique<Sandbox>(APP_NAME);
	Corylium::CreateApplication(*app);
	Corylium::Log::Error("This is {}{}{} ({}) error", "t", "w", "o", 2);
}