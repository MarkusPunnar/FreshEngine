#pragma once

#include "Fresh/Core/Window.h"

#include <GLFW/glfw3.h>

namespace Fresh {

	class WindowsWindow : public Window {

	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		void SetEventCallback(const CallbackFn& callback) { m_Data.EventCallback = callback; }
		inline uint32_t GetHeight() const { return m_Data.Width; }
		inline uint32_t GetWidth() const { return m_Data.Height; }

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		
		void Init(const WindowProperties& properties);
		void Shutdown();

	private:

		GLFWwindow* m_Window;

		struct WindowData {

			std::string Title;
			uint32_t Width, Height;
			bool VSync;

			CallbackFn EventCallback;
		};

		WindowData m_Data;
	};
 
}
