#pragma once
#include "Application.h"

#ifdef TB_PLATFORM_WINDOWS

extern Tube::Application* Tube::CreateApplication();

int main(int argc, char** argv) {
	
	auto app = Tube::CreateApplication();
	app->Run();
	delete(app);

}

#endif // TB_PLATFORM_WINDOWS
