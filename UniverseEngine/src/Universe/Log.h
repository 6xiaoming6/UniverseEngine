#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"


namespace Universe{

	class UN_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

//引擎日志宏
#define UN_CORE_ERROR(...)	Universe::Log::GetCoreLogger()->error(__VA_ARGS__)
#define UN_CORE_WARN(...)	Universe::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define UN_CORE_INFO(...)	Universe::Log::GetCoreLogger()->info(__VA_ARGS__)
#define UN_CORE_TRACE(...)	Universe::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define UN_CORE_FATAL(...)	Universe::Log::GetCoreLogger()->fatal(__VA_ARGS__)


//客户端日志宏
#define UN_CLIENT_ERROR(...)	Universe::Log::GetClientLogger()->error(__VA_ARGS__)
#define UN_CLIENT_WARN(...)		Universe::Log::GetClientLogger()->warn(__VA_ARGS__)
#define UN_CLIENT_INFO(...)		Universe::Log::GetClientLogger()->info(__VA_ARGS__)
#define UN_CLIENT_TRACE(...)	Universe::Log::GetClientLogger()->trace(__VA_ARGS__)
#define UN_CLIENT_FATAL(...)	Universe::Log::GetClientLogger()->fatal(__VA_ARGS__)	