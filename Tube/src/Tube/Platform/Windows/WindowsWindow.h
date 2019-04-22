#pragma once
#include "Tube/Window.h"
#include "GLFW/glfw3.h"

namespace Tube {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& properties);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallBack = callback; }


		void SetVSync(bool enabled) override;
		bool IsVsync() const override;

	private:
		void Init(const WindowProps& properties);
		virtual void ShutDown();

	private:
		GLFWwindow* m_Window;

		struct WindowData {
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallBack;
		};

		WindowData m_Data;
	

	};
}
