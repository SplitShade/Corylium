#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include <utility>
#include <string>
#include "spdlog/logger.h"

namespace Corylium {

	class Log
	{
	public:
		[[nodiscard]] static constexpr std::shared_ptr<spdlog::logger>& GetCoreLogger() { return sCoreLogger; }
		[[nodiscard]] CORYLIUM_API static constexpr std::shared_ptr<spdlog::logger>& GetClientLogger() { return sClientLogger; }

		static void Init(const std::string ClientLoggerName);

		template<typename ...Args>
		static void CoreError(spdlog::format_string_t<Args...> fmt, Args&& ...args);

		template<typename ...Args>
		static void Error(spdlog::format_string_t<Args...> fmt, Args&& ...args);

		template<typename ...Args>
		static void CoreInfo(spdlog::format_string_t<Args...> fmt, Args&& ...args);

		template<typename ...Args>
		static void Info(spdlog::format_string_t<Args...> fmt, Args&& ...args);

		Log() = delete;
		Log(const Log&) = delete;
		Log(Log&&) = delete;
		Log& operator=(const Log&) = delete;
		Log& operator=(Log&&) = delete;
		~Log() = delete;

	private:
		static inline std::shared_ptr<spdlog::logger> sCoreLogger;
		static inline std::shared_ptr<spdlog::logger> sClientLogger;
	};

}

#include "Log_impl.h"
