#pragma once
#include "Event.h"

namespace Tube {

	class TUBE_API MouseMovedEvent : public Event
	{

	public:
		MouseMovedEvent(float x, float y) 
			: m_MouseX(x), m_MouseY(y)
		{}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseX; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);
		EVENT_CLASS_TYPE(MouseMoved)

	private:
		float m_MouseX, m_MouseY;
	};

	class TUBE_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			:m_ScrollX(xOffset), m_ScrollY(yOffset)
		{}

		inline float GetXOffset() const { return m_ScrollX; }
		inline float GetYOffset() const { return m_ScrollY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_ScrollX << ", " << m_ScrollY;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);
		EVENT_CLASS_TYPE(MouseScrolled)

	private:
		float m_ScrollX, m_ScrollY;

	};

	class TUBE_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
	protected:
		MouseButtonEvent(int button)
			:m_Button(button)
		{

		}

		int m_Button;

	};

	class TUBE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent (" << m_Button << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)

	};

	class TUBE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override {

			std::stringstream ss;
			ss << "MouseButtonReleasedEvent (" << m_Button << ")";
			return ss.str();

		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}