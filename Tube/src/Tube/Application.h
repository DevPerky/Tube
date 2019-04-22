#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Tube/Events/ApplicationEvent.h"

#include "Window.h"

namespace Tube {

	class TUBE_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& event);


	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool OnWindowClose(WindowCloseEvent& e);

	};

	//To be defined in client
	Application* CreateApplication();


}