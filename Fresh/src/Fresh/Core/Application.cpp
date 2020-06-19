#include "frpch.h"
#include "Application.h"

namespace Fresh {

	Application::Application() {
		
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(FR_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application() {
	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}

	bool Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(FR_BIND_EVENT_FN(Application::OnWindowClose));
		return true;
	}

	bool Application::OnWindowClose(WindowCloseEvent& event) {
		m_Running = false;
		return true;
	}
}