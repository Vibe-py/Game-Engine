#pragma once

#ifdef PZ_PLATFORM_WINDOWS
	#ifdef PZ_BUILD_DLL
		#define PRETZEL_API __declspec(dllexport)
	#else
		#define PRETZEL_API __declspec(dllimport)
	#endif
#else
#error Pretzel only supports windows
#endif

#define BIT(x) (1 << x)