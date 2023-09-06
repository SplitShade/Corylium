export module Application;

#include "Core.h"

//import <functional>;
//import <iostream>;

namespace Corylium {

	export class CORYLIUM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	/*export void CORYLIUM_API SetApplicationInitFunction(std::function<Application* ()> CreateApplication);

	export void CORYLIUM_API Initialize();*/

}