#pragma once

#if JIGL_PLATFORM_WINDOWS

extern Jiggle::Application* Jiggle::CreateApplication();

int main(int argc, char** argv) {

	Jiggle::Log::Init();

	JIGL_CORE_INFO("Logging Initialized.");
	JIGL_INFO("Logging Initialized.");
	
	auto app = Jiggle::CreateApplication();
	app->Run();
	delete app;
}

#endif
