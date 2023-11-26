#pragma once
#include "Core.h"

namespace Corylium {

	/// <summary>
	/// Application class which is meant to be inherited by an app that uses the Corylium API
	/// </summary>
	class CORYLIUM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

}