#pragma once
#include "tbpch.h"

#include "Core.h"
#include "Events/Event.h"

namespace Tube {

	struct WindowProps {
		std::string Title;
		unsigned int Width, Height;

		WindowProps(const std::string& title = "Tube Engine", unsigned int width = 1280, unsigned int height = 720)
			:Title(title), Width(width), Height(height)
		{
		}

	};

	class TUBE_API Window {

	public:
		using EventCallbackFn = std::function<void(Event& e)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVsync() const = 0;

		static Window* Create(const WindowProps& = WindowProps());


	};


}