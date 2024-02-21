#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Jiggle {
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("JIGGLE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("SPRINGBOX");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}