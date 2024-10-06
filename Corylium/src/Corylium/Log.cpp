#include "Log.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Corylium {
	
	void Log::Init(const std::string ClientLoggerName)
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		sCoreLogger = spdlog::stdout_color_mt("CORYLIUM");
		sClientLogger = spdlog::stdout_color_mt(ClientLoggerName);

		sCoreLogger->set_level(spdlog::level::trace);
		sClientLogger->set_level(spdlog::level::trace);
	}
}
