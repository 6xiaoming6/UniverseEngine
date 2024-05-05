#pragma once

#ifdef UN_PLATFORM_WINDOWS
	#ifdef UN_BUILD_DLL
		#define UN_API __declspec(dllexport)
	#else
		#define UN_API __declspec(dllimport)
	#endif // UN_BUILD_DLL
#else
	#error Universe only in windows!

#endif // UN_PLATFORM_WINDOW

#define BIT(X) (1 << X)