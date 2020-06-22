#include "frpch.h"
#include "Application.h"

#include <glad/glad.h>

namespace Fresh {

	Application* Application::s_Instance = nullptr;

	Application::Application() {
		
		if (s_Instance != nullptr) {
			FR_CORE_ERROR("Application is already defined!");
		}
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(FR_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application() {
	}

	void Application::Run() {
		while (m_Running) {
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
			for (Layer* layer : m_LayerStack) {
				layer->OnUpdate();
			}
			m_Window->OnUpdate();
		}
	}

	bool Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(FR_BIND_EVENT_FN(Application::OnWindowClose));
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.isHandled) {
				break;
			}
		}
		return true;
	}

	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay) {
		m_LayerStack.PushOverlay(overlay);
	}

	bool Application::OnWindowClose(WindowCloseEvent& event) {
		m_Running = false;
		return true;
	}
}