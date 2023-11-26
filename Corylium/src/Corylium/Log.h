#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Corylium {

	class CORYLIUM_API Log
	{
	public:
		static constexpr std::shared_ptr<spdlog::logger>& GetCoreLogger() { return sCoreLogger; }
		static constexpr std::shared_ptr<spdlog::logger>& GetClientLogger() { return sClientLogger; }

		static void Initialize();

		template<typename ...Args>
		static void CoreError(Args ...args)
		{
			return;
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