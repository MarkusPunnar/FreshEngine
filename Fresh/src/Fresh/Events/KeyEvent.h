#pragma once

#include "Event.h"

namespace Fresh {

	class KeyEvent : public Event {

	public:
		int GetCategoryFlags() const override {
			return CategoryKeyBoard | CategoryInput;
		}

		inline int GetKeyCode() const { return m_KeyCode; }

	protected:
		
		KeyEvent(int keyCode)
			: m_KeyCode(keyCode) {};

		int m_KeyCode;

	};

	class KeyTypedEvent : public KeyEvent {

	public:

		KeyTypedEvent(int keyCode)
			: KeyEvent(keyCode) {};

		FR_EVENT_TYPE(KeyTyped);

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}
	};

	class KeyPressedEvent : public KeyEvent {

	public:

		KeyPressedEvent(int keyCode, int repeatCount)
			: KeyEvent(keyCode), m_RepeatCount(repeatCount) {};

		FR_EVENT_TYPE(KeyPressed);

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

	private:
		int m_RepeatCount;
	
	};

	class KeyReleasedEvent : public KeyEvent {

	public:

		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode) {};

		FR_EVENT_TYPE(KeyReleased);

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

	};

}
