#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Universe {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("UNIVERSE");
		spdlog::set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		spdlog::set_level(spdlog::level::trace);
	}

}