#pragma once
#include "Application.h"

#ifdef TB_PLATFORM_WINDOWS

extern Tube::Application* Tube::CreateApplication();

int main(int argc, char** argv) {

	Tube::Log::Init();

	TB_CORE_WARN("Initialized Log");
	int a = 5;
	TB_INFO("Hello! Var = {0}", 5);

	auto app = Tube::CreateApplication();
	app->Run();
	delete(app);

}

#endif // TB_PLATFORM_WINDOWS
