#pragma once

#include "Base.h"
#include "Window.h"
#include "LayerStack.h"

#include "Fresh/Events/WindowEvent.h"

namespace Fresh {
	
	class Application {

	public:

		Application();
		virtual ~Application();

		void Run();

		bool OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() const { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:

		bool OnWindowClose(WindowCloseEvent& e);

	private:
		
		static Application* s_Instance;

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		unsigned int m_VertexArrayID, m_VertexBufferID, m_IndexBufferID;
	};

	Application* CreateApplication();

}