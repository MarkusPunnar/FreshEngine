#pragma once

#include "frpch.h"
#include "Fresh/Events/Event.h"

namespace Fresh {

	struct WindowProperties {
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProperties(const std::string& title = "Fresh Engine", uint32_t width = 1280, uint32_t height = 720)
			: Title(title), Width(width), Height(height) {};
	};

	class Window {

	public:

		using CallbackFn = std::function<void(Event&)>;

		virtual ~Window() {};

		virtual void OnUpdate() = 0;
		virtual void SetEventCallback(const CallbackFn& callback) = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProperties& properties = WindowProperties());

	private:
		
	};

}