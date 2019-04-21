#pragma once
#include "Core.h"
#include "Events/ApplicationEvent.h"

namespace Tube {

	class TUBE_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in client
	Application* CreateApplication();


}