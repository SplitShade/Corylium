#pragma once

#include "Core.h"
#include "Application.h"

namespace Corylium {

	/// @brief Used to pass a unique_ptr to an object dervied from a Corylium::Application
	/// @param DerivedApplication 
	/// @return void
	void CORYLIUM_API CreateApplication(Application& DerivedApplication);

	void Initialize(Application& DerivedApplication);
}
