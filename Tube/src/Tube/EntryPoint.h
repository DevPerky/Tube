#pragma once
#include "Application.h"

#ifdef TB_PLATFORM_WINDOWS

extern Tube::Application* Tube::CreateApplication();

int main(int argc, char** argv) {

	Tube::Log::Init();

	auto app = Tube::CreateApplication();
	app->Run();
	delete(app);

	return 1;
}

#endif // TB_PLATFORM_WINDOWS
