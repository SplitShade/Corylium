#pragma once

#include "Core.h"

namespace Corylium {

	/// @brief Application class which is meant to be inherited by an app that uses the Corylium API
	class Application
	{
	public:
		CORYLIUM_API Application();
		CORYLIUM_API explicit Application(std::string_view Name);
		CORYLIUM_API virtual ~Application();

		CORYLIUM_API void Run();

		CORYLIUM_API std::string GetName() const { return _name; }

		
	private:
		std::string _name = "CLIENT_APP";
	};

}