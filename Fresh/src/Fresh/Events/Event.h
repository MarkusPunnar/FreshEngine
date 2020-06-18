#pragma once

#include "frpch.h"

#include "Fresh/Core.h"

namespace Fresh {

	enum EventType {

		None = 0,
		KeyPressed, KeyReleased,
		MouseButtonClicked, MouseButtonReleased, MouseScrolled, MouseMoved,
		WindowResized, WindowClosed

	};

	enum EventCategory {

		CategoryInput = BIT(0),
		CategoryMouse = BIT(1),
		CategoryMouseButton = BIT(2),
		CategoryKeyBoard = BIT(3),
		CategoryWindow = BIT(4)

	};

#define FR_EVENT_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							virtual const EventType GetEventType() const { return GetStaticType(); }\
							virtual const char* GetName() const { return #type; }
							

	class Event {

	public:

		virtual const EventType GetEventType() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const = 0;

		inline bool IsInCategory(EventCategory category) {
			return category & GetCategoryFlags();
		}

		friend class EventDispatcher;

	protected:
		bool m_Handled = false;
	};


	class EventDispatcher {

		template<typename T>
		using EventFn = std::function<bool(T&)>;
		
	public:

		EventDispatcher(Event& event)
			: m_Event(event) {};

		template<typename T>
		bool Dispatch(EventFn<T> callback) {
			if (m_Event.GetEventType() == T::GetStaticType()) {
				m_Event.m_Handled == callback(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}

}