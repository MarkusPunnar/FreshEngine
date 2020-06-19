#pragma once

#include "Base.h"
#include "Window.h"

#include "Fresh/Events/WindowEvent.h"

namespace Fresh {
	
	class Application {

	public:

		Application();
		virtual ~Application();

		void Run();

		bool OnEvent(Event& e);

	private:

		bool OnWindowClose(WindowCloseEvent& e);

	private:
		
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();

}