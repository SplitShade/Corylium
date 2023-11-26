#pragma once
#include "Core.h"
#include "Application.h"
#include <functional>


namespace Corylium {

	/// <summary>
	/// Used to pass a function that creates an app dervied from a Corylium::Application, for example:
	/// <code>
	/// class DerviedApplication : public Corylium::Application {
	/// }
	/// 
	/// Corylium::Application* CreateApplication()
	/// {
	/// 	return new DerivedApplication();
	/// }
	/// </code>
	/// </summary>
	/// <param name="CreateApplication"></param>
	/// <returns></returns>
	void CORYLIUM_API SetApplicationInitFunction(std::function<Application* ()> CreateApplication);

	/// <summary>
	/// The entrypoint of a Corylium application, defined by the Corylium API
	/// </summary>
	/// <returns></returns>
	void CORYLIUM_API Initialize();

}