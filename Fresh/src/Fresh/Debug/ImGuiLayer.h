#pragma once

#include "Fresh/Core/Layer.h"
#include "Fresh/Core/Application.h"
#include "Fresh/Core/KeyCodes.h"

#include "Fresh/Events/Event.h"
#include "Fresh/Events/KeyEvent.h"
#include "Fresh/Events/MouseEvent.h"
#include "Fresh/Events/WindowEvent.h"

namespace Fresh {

	class ImGuiLayer : public Layer {

	public:

		ImGuiLayer();
		~ImGuiLayer() = default;

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& e) override;

	private:

		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleased(MouseButtonReleasedEvent& e);
		bool OnMouseScrolled(MouseScrolledEvent &e);
		bool OnMouseMoved(MouseMovedEvent& e);

		bool OnKeyPressed(KeyPressedEvent& e);
		bool OnKeyReleased(KeyReleasedEvent& e);
		bool OnKeyTyped(KeyTypedEvent& e);

		bool OnWindowResized(WindowResizedEvent& e);

	private:
		float m_Time = 0.0f;
	};

}