#pragma once

#ifdef CRLY_PLATFORM_WINDOWS
	#ifdef CRLY_BUILD_DLL
		#define CORYLIUM_API __declspec(dllexport)
	#else
		#define CORYLIUM_API __declspec(dllimport)
	#endif
#else
	#error Corylium only supports Windows!
#endif 

