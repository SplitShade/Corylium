#include "Log.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Corylium {
	
	void Log::Init(const std::string_view ClientLoggerName)
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		_sCoreLogger = spdlog::stdout_color_mt(std::string(CRLY_LOGGER_DEFAULT_NAME));
		_sClientLogger = spdlog::stdout_color_mt(std::string(ClientLoggerName));

		_sCoreLogger->set_level(spdlog::level::trace);
		_sClientLogger->set_level(spdlog::level::trace);
	}
}
