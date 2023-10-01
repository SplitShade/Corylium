module;
#include "Core.hpp"

export module Application;

namespace Corylium {

	/// <summary>
	/// Application class which is meant to be inherited by an app that uses the Corylium API
	/// </summary>
	export class CORYLIUM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

}