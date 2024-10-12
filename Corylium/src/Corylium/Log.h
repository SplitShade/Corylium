#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include <utility>
#include <string>
#include "spdlog/logger.h"

static constexpr std::string_view CRLY_LOGGER_DEFAULT_NAME = "CORYLIUM";

namespace Corylium {

	class Log
	{
	public:
		[[nodiscard]] static constexpr std::shared_ptr<spdlog::logger>& GetCoreLogger() { return _sCoreLogger; }
		[[nodiscard]] CORYLIUM_API static constexpr std::shared_ptr<spdlog::logger>& GetClientLogger() { return _sClientLogger; }

		static void Init(const std::string_view ClientLoggerName);

		template<typename ...Args>
		static void CoreError(spdlog::format_string_t<Args...> fmt, Args&& ...args);

		template<typename ...Args>
		static void Error(spdlog::format_string_t<Args...> fmt, Args&& ...args);

		template<typename ...Args>
		static void CoreWarn(spdlog::format_string_t<Args...> fmt, Args&& ...args);

		template<typename ...Args>
		static void Warn(spdlog::format_string_t<Args...> fmt, Args&& ...args);

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
		static inline std::shared_ptr<spdlog::logger> _sCoreLogger;
		static inline std::shared_ptr<spdlog::logger> _sClientLogger;

	};

}

#include "Log_impl.h"
