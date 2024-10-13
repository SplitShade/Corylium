#include "crlypch.h"
#include "Log.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

static constexpr std::string_view LOGGING_LEVEL = "trace";

namespace Corylium {
	
	void Log::Init(const std::string_view ClientLoggerName)
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		_sCoreLogger = spdlog::stdout_color_mt(std::string(CRLY_LOGGER_DEFAULT_NAME));
		_sClientLogger = spdlog::stdout_color_mt(std::string(ClientLoggerName));
		if (LOGGING_LEVEL == "trace")
		{
			_sCoreLogger->set_level(spdlog::level::trace);
			_sClientLogger->set_level(spdlog::level::trace);
		}
		else if (LOGGING_LEVEL == "debug")
		{
			_sCoreLogger->set_level(spdlog::level::debug);
			_sClientLogger->set_level(spdlog::level::debug);
		}
		else if (LOGGING_LEVEL == "info")
		{
			_sCoreLogger->set_level(spdlog::level::info);
			_sClientLogger->set_level(spdlog::level::info);
		}
		else if (LOGGING_LEVEL == "warn")
		{
			_sCoreLogger->set_level(spdlog::level::warn);
			_sClientLogger->set_level(spdlog::level::warn);
		}
		else if (LOGGING_LEVEL == "err")
		{
			_sCoreLogger->set_level(spdlog::level::err);
			_sClientLogger->set_level(spdlog::level::err);
		}
		else if (LOGGING_LEVEL == "critical")
		{
			_sCoreLogger->set_level(spdlog::level::critical);
			_sClientLogger->set_level(spdlog::level::critical);
		}
		else if (LOGGING_LEVEL == "off")
		{
			_sCoreLogger->set_level(spdlog::level::off);
			_sClientLogger->set_level(spdlog::level::off);
		}
		else
		{
			_sCoreLogger->set_level(spdlog::level::trace);
			_sClientLogger->set_level(spdlog::level::trace);
			CoreWarn("Logging level chosen setting unsupported. Using trace.");
		}

	}
}
