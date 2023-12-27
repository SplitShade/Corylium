#pragma once

#include "Core.h"
#include <string>

namespace Corylium {

	/// <summary>
	/// Application class which is meant to be inherited by an app that uses the Corylium API
	/// </summary>
	class Application
	{
	public:
		CORYLIUM_API Application();
		CORYLIUM_API explicit Application(std::string_view Name);
		CORYLIUM_API virtual ~Application();

		CORYLIUM_API void Run();

		CORYLIUM_API std::string GetName() const;

	private:
		std::string _name = "CLIENT_APP";
	};

}