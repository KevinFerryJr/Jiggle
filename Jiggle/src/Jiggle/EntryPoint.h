#pragma once

#if JIGL_PLATFORM_WINDOWS

extern Jiggle::Application* Jiggle::CreateApplication();

int main(int argc, char** argv) {

	printf("Loading Jiggle Engine...\n");
	
	auto app = Jiggle::CreateApplication();
	app->Run();
	delete app;
}

#endif
