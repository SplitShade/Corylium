
import Corylium;


class Sandbox : public Corylium::Application {
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Corylium::Application* CreateApplication()
{
	return new Sandbox();
}

int main(int argc, char** argv) {
	Corylium::SetApplicationInitFunction(CreateApplication);
	Corylium::Initialize();
	//a::fun();
	
	
}