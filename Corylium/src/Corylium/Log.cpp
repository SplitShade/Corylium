module;
#include "spdlog/spdlog.h"

module Log;

namespace Corylium {
	std::shared_ptr<spdlog::logger> Log::sCoreLogger;
	std::shared_ptr<spdlog::logger> Log::sClientLogger;
}