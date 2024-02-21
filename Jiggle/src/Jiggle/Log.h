#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Jiggle {

	class JIGGLE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core log definitions
#define JIGL_CORE_TRACE(...)  ::Jiggle::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define JIGL_CORE_INFO(...)   ::Jiggle::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JIGL_CORE_WARN(...)   ::Jiggle::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JIGL_CORE_ERROR(...)  ::Jiggle::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JIGL_CORE_FATAL(...)  ::Jiggle::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log definitions
#define JIGL_TRACE(...)       ::Jiggle::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JIGL_INFO(...)        ::Jiggle::Log::GetClientLogger()->info(__VA_ARGS__)
#define JIGL_WARN(...)        ::Jiggle::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JIGL_ERROR(...)       ::Jiggle::Log::GetClientLogger()->error(__VA_ARGS__)
#define JIGL_FATAL(...)       ::Jiggle::Log::GetClientLogger()->fatal(__VA_ARGS__)
