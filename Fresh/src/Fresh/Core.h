#pragma once

#ifdef FRESH_PLATFORM_WINDOWS
	#ifdef FRESH_BUILD_DLL
		#define FRESH_API __declspec(dllexport)
	#else
		#define FRESH_API __declspec(dllimport)
	#endif
#else
	#error Fresh only supports Windows!
#endif