#pragma once

#ifdef JIGL_PLATFORM_WINDOWS 
	#ifdef JIGL_BUILD_DLL
		#define JIGGLE_API __declspec(dllexport)
	#else
		#define JIGGLE_API __declspec(dllimport)	
	#endif
#else
	#error Jiggle currently only supports Windows!
#endif
