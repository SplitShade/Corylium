export module Application;

#include "Core.h"

namespace Corylium {

	export class CORYLIUM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	/// <summary>
	/// Creates Application, is defined in CLIENT
	/// </summary>
	/// <returns>Application*</returns>
	export Application* CreateApplication();

}