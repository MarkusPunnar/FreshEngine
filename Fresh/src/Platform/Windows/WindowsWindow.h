#pragma once

#include "Fresh/Core/Window.h"
#include "Fresh/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Fresh {

	class WindowsWindow : public Window {

	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		void SetEventCallback(const CallbackFn& callback) { m_Data.EventCallback = callback; }
		inline uint32_t GetHeight() const { return m_Data.Height; }
		inline uint32_t GetWidth() const { return m_Data.Width; }

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline void* GetNativeWindow() const { return m_Window; }

	private:
		
		void Init(const WindowProperties& properties);
		void Shutdown();

	private:

		GLFWwindow* m_Window;
		GraphicsContext* m_Context;

		struct WindowData {

			std::string Title;
			uint32_t Width, Height;
			bool VSync;

			CallbackFn EventCallback;
		};

		WindowData m_Data;
	};
 
}
