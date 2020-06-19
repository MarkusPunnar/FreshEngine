#pragma once

#include "Event.h"

namespace Fresh {

	class WindowResizedEvent : public Event {

	public:

		WindowResizedEvent(uint32_t width, uint32_t height)
			: m_Width(width), m_Height(height) {};

		FR_EVENT_TYPE(WindowResized);

		int GetCategoryFlags() const override {
			return CategoryWindow | CategoryInput;
		}

		 std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizedEvent: (" << m_Width << ", " << m_Height << ")";
			return ss.str();
		}

		inline uint32_t GetWidth() const { return m_Width; }
		inline uint32_t GetHeight() const { return m_Height; }

	private:
		uint32_t m_Width, m_Height;
	};

	class WindowCloseEvent : public Event {

	public:
		WindowCloseEvent() {};

		FR_EVENT_TYPE(WindowClosed);

		int GetCategoryFlags() const override {
			return CategoryWindow;
		}

		std::string ToString() const override {
			return GetName();
		}
	};


}