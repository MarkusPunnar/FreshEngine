#pragma once

#include "Base.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Fresh {

	class Logger {

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define FR_CORE_ERROR(...) Fresh::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define FR_CORE_WARN(...)  Fresh::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define FR_CORE_INFO(...)  Fresh::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define FR_CORE_TRACE(...) Fresh::Logger::GetCoreLogger()->trace(__VA_ARGS__)

//Client log macros
#define FR_ERROR(...) Fresh::Logger::GetClientLogger()->error(__VA_ARGS__)
#define FR_WARN(...)  Fresh::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define FR_INFO(...)  Fresh::Logger::GetClientLogger()->info(__VA_ARGS__)
#define FR_TRACE(...) Fresh::Logger::GetClientLogger()->trace(__VA_ARGS__)