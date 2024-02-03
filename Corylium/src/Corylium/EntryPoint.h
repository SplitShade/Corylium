#pragma once

#include "Core.h"
#include "Application.h"

namespace Corylium {

	/// <summary>
	/// Used to pass a unique_ptr to an object dervied from a Corylium::Application
	/// </summary>
	/// <param name="DerivedApplication"></param>
	/// <returns></returns>
	void CORYLIUM_API CreateApplication(Application& DerivedApplication);

	void Initialize(Application& DerivedApplication);
}
