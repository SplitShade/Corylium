#include "Log.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Corylium {
	std::shared_ptr<spdlog::logger> Log::sCoreLogger;
	std::shared_ptr<spdlog::logger> Log::sClientLogger;

	void Log::Initialize()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		sCoreLogger = spdlog::stdout_color_mt("CORYLIUM");
		sClientLogger = spdlog::stdout_color_mt("APP");

		sCoreLogger->set_level(spdlog::level::trace);
		sClientLogger->set_level(spdlog::level::trace);
	}
}

