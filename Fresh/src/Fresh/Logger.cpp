#include "frpch.h"
#include "Logger.h"

namespace Fresh {

	std::shared_ptr<spdlog::logger> Logger::s_coreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_clientLogger;

	void Logger::Init() 
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_coreLogger = spdlog::stdout_color_mt("FRESH");
		s_coreLogger->set_level(spdlog::level::trace);
		s_clientLogger = spdlog::stderr_color_mt("APP");
		s_clientLogger->set_level(spdlog::level::trace);
	}
}