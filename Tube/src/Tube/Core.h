#pragma once

#ifdef TB_PLATFORM_WINDOWS

	#ifdef TB_BUILD_DLL
		#define TUBE_API __declspec(dllexport)
	#else
		#define TUBE_API __declspec(dllimport)
	#endif // TB_BUILD_DLL
#else
	#error Tube only supports windows!
#endif //TB_PLATFORM_WINDOWS

#define BIT(x) (1 << x)
