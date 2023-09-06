export module EntryPoint;

import Application;
import <functional>;
import <iostream>;
#include "Core.h"

namespace Corylium {

	export void CORYLIUM_API SetApplicationInitFunction(std::function<Application* ()> CreateApplication);

	export void CORYLIUM_API Initialize();
	//export void CORYLIUM_API fun();
}