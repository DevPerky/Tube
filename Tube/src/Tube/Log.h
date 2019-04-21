#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Tube {
	
	class TUBE_API Log 
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger>  s_CoreLogger;
		static std::shared_ptr<spdlog::logger>  s_ClientLogger;


	};

}

//Core log macros
#define TB_CORE_TRACE(...)   ::Tube::Log::getCoreLogger()->trace (__VA_ARGS__)
#define TB_CORE_INFO(...)    ::Tube::Log::getCoreLogger()->info  (__VA_ARGS__)
#define TB_CORE_WARN(...)    ::Tube::Log::getCoreLogger()->warn  (__VA_ARGS__)
#define TB_CORE_ERROR(...)   ::Tube::Log::getCoreLogger()->error (__VA_ARGS__)
#define TB_CORE_FATAL(...)   ::Tube::Log::getCoreLogger()->fatal (__VA_ARGS__)

//Client log macros
#define TB_TRACE(...)        ::Tube::Log::getClientLogger()->trace (__VA_ARGS__)
#define TB_INFO(...)         ::Tube::Log::getClientLogger()->info  (__VA_ARGS__)
#define TB_WARN(...)         ::Tube::Log::getClientLogger()->warn  (__VA_ARGS__)
#define TB_ERROR(...)        ::Tube::Log::getClientLogger()->error (__VA_ARGS__)
#define TB_FATAL(...)        ::Tube::Log::getClientLogger()->fatal (__VA_ARGS__)


