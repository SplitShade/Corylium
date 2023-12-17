#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include <utility>
#include <string>
#include "spdlog/logger.h"

namespace Corylium {

	class CORYLIUM_API Log
	{
	public:
		static constexpr std::shared_ptr<spdlog::logger>& GetCoreLogger() { return sCoreLogger; }
		static constexpr std::shared_ptr<spdlog::logger>& GetClientLogger() { return sClientLogger; }

		static void Initialize();

		template<typename ...Args>
		static void CoreError(spdlog::format_string_t<Args...> fmt, Args&& ...args)
		{
			sCoreLogger->error(fmt, std::forward<Args>(args)...);
		}

		template<typename ...Args>
		static void ClientError(spdlog::format_string_t<Args...> fmt, Args&& ...args)
		{
			sClientLogger->error(fmt, std::forward<Args>(args)...);
		}
		
		Log() = delete;
		Log(const Log&) = delete;
		Log(Log&&) = delete;
		Log& operator=(const Log&) = delete;
		Log& operator=(Log&&) = delete;
		~Log() = delete;

	private:
		static std::shared_ptr<spdlog::logger> sCoreLogger;
		static std::shared_ptr<spdlog::logger> sClientLogger;
	};

}