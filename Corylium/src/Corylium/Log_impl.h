#pragma once
//#include "Core.h"

namespace Corylium {

	#if defined(CRLY_DEBUG) || defined(CRLY_RELEASE)
	template<typename ...Args>
	static void Log::CoreError(spdlog::format_string_t<Args...> fmt, Args&& ...args)
	{
		GetCoreLogger()->error(fmt, std::forward<Args>(args)...);
	}

	template<typename ...Args>
	static void Log::Error(spdlog::format_string_t<Args...> fmt, Args&& ...args)
	{
		GetClientLogger()->error(fmt, std::forward<Args>(args)...);
	}

	template<typename ...Args>
	static void Log::CoreWarn(spdlog::format_string_t<Args...> fmt, Args&& ...args)
	{
		GetCoreLogger()->warn(fmt, std::forward<Args>(args)...);
	}

	template<typename ...Args>
	static void Log::Warn(spdlog::format_string_t<Args...> fmt, Args&& ...args)
	{
		GetClientLogger()->warn(fmt, std::forward<Args>(args)...);
	}

	template<typename ...Args>
	static void Log::CoreInfo(spdlog::format_string_t<Args...> fmt, Args&& ...args)
	{
		GetCoreLogger()->info(fmt, std::forward<Args>(args)...);
	}

	template<typename ...Args>
	static void Log::Info(spdlog::format_string_t<Args...> fmt, Args&& ...args)
	{
		GetClientLogger()->info(fmt, std::forward<Args>(args)...);
	}
	#else
	template<typename ...Args>
	static void Log::CoreError(spdlog::format_string_t<Args...> fmt, Args&& ...args)
	{
	}

	template<typename ...Args>
	static void Log::Error(spdlog::format_string_t<Args...> fmt, Args&& ...args)
	{
	}

	template<typename ...Args>
	static void Log::CoreInfo(spdlog::format_string_t<Args...> fmt, Args&& ...args)
	{
	}

	template<typename ...Args>
	static void Log::Info(spdlog::format_string_t<Args...> fmt, Args&& ...args)
	{
	}
	#endif
}
