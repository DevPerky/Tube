#include "tbpch.h"
#include "WindowsWindow.h"
#include "Tube/Events/MouseEvent.h"
#include "Tube/Events/KeyEvent.h"
#include "Tube/Events/ApplicationEvent.h"

namespace Tube {

	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* message){
		TB_CORE_ERROR("GLFW Error! ({0}): {1}", error, message);
	}

	Window* Window::Create(const WindowProps& properties) {
		return new WindowsWindow(properties);
	}

	WindowsWindow::WindowsWindow(const WindowProps& properties) {
		Init(properties);
	}

	WindowsWindow::~WindowsWindow() {
		ShutDown();
	}
	
	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::Init(const WindowProps& properties) {
		m_Data.Title = properties.Title;
		m_Data.Width = properties.Width;
		m_Data.Height = properties.Height;

		TB_CORE_INFO("Creating Window '{0}' ({1}, {2})", properties.Title, properties.Width, properties.Height);

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			TB_CORE_ASSERT(success, "Could not initialize GLFW");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(properties.Width, properties.Height, properties.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);


		//Set glfw callbacks

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height){

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowResizeEvent event(width, height);
			data.Width = width;
			data.Height = height;
			data.EventCallBack(event);

		});


		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallBack(event);
		});


		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			switch (action)
			{
				case GLFW_PRESS: {
					KeyPressedEvent event(key, 0);
					data.EventCallBack(event);
					break;
				}
				case GLFW_RELEASE: {
					KeyReleasedEvent event(key);
					data.EventCallBack(event);
					break;
				}
				case GLFW_REPEAT: {
					KeyPressedEvent event(key, 1);
					data.EventCallBack(event);
					break;
				}

			}
		});


		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			switch (action) {
				case GLFW_PRESS: {
					MouseButtonPressedEvent event(button);
					data.EventCallBack(event);
					break;
				}
				case GLFW_RELEASE: {
					MouseButtonReleasedEvent event(button);
					data.EventCallBack(event);
					break;
				}
			}

		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallBack(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			MouseMovedEvent event((float)xPos, (float)yPos);
			data.EventCallBack(event);
		});

	}

	void WindowsWindow::ShutDown() {
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled) {
		if (enabled) {
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVsync() const {
		return m_Data.VSync;
	}

}