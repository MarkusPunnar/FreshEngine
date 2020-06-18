#pragma once

#include "Event.h"

namespace Fresh {

	class MouseMovedEvent : public Event {

	public:

		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {};

		FR_EVENT_TYPE(MouseMoved);

		int GetCategoryFlags() const override {
			return CategoryMouse | CategoryInput;
		}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: (" << m_MouseX << ", " << m_MouseY << ")";
			return ss.str();
		}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

	private:
		float m_MouseX, m_MouseY;
	};

	class MouseScrolledEvent : public Event {

	public:

		MouseScrolledEvent(float xOffset, float yOffset)
			: m_OffsetX(xOffset), m_OffsetY(yOffset) {};

		FR_EVENT_TYPE(MouseScrolled);

		int GetCategoryFlags() const override {
			return CategoryMouse | CategoryInput;
		}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: (" << m_OffsetX << ", " << m_OffsetY << ")";
			return ss.str();
		}

		inline float GetOffsetX() const { return m_OffsetX; }
		inline float GetOffsetY() const { return m_OffsetY; }

	private:
		float m_OffsetX, m_OffsetY;
	};


	class MouseButtonEvent : public Event {

	public:

		MouseButtonEvent(int button)
			: m_Button(button) {};

		int GetCategoryFlags() const override {
			return CategoryMouseButton | CategoryMouse | CategoryInput;
		}

		inline int GetButton() const { return m_Button; }

	protected:
		int m_Button;
	};

	class MouseButtonClickedEvent : public MouseButtonEvent {

	public:

		MouseButtonClickedEvent(int button)
			: MouseButtonEvent(button) {};

		FR_EVENT_TYPE(MouseButtonClicked);

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonClickedEvent: " << m_Button;
			return ss.str();
		}
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {

	public:

		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {};

		FR_EVENT_TYPE(MouseButtonReleased);

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}
	};
}