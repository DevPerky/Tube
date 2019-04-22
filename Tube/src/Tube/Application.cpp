#include "tbpch.h"
#include "Application.h"
#include "Core.h"

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)


namespace Tube {

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() {

	}

	void Application::Run() {
		TB_CORE_TRACE("Welcome to the Tube Engine!");

		while (m_Running) {
			m_Window->OnUpdate();

		}


	}

	bool Application::OnWindowClose(WindowCloseEvent& event) {
		m_Running = false;
		return true;
	}

	void Application::OnEvent(Event& e) {

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		TB_CORE_TRACE("{0}", e.ToString());
	}


}

