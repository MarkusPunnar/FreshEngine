#include "frpch.h"
#include "ImGuiLayer.h"

#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"

//Temporary
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Fresh {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer") {};

	void ImGuiLayer::OnAttach() {

		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		Application& app = Application::Get();
		io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());

		io.KeyMap[ImGuiKey_Tab]			= FR_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow]   = FR_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow]  = FR_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow]		= FR_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow]   = FR_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp]		= FR_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown]	= FR_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home]		= FR_KEY_HOME;
		io.KeyMap[ImGuiKey_End]			= FR_KEY_END;
		io.KeyMap[ImGuiKey_Insert]		= FR_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete]		= FR_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace]	= FR_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space]		= FR_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter]		= FR_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape]		= FR_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_KeyPadEnter] = FR_KEY_KP_ENTER;
		io.KeyMap[ImGuiKey_A]			= FR_KEY_A;
		io.KeyMap[ImGuiKey_C]			= FR_KEY_C;
		io.KeyMap[ImGuiKey_V]			= FR_KEY_V;
		io.KeyMap[ImGuiKey_X]			= FR_KEY_X;
		io.KeyMap[ImGuiKey_Y]			= FR_KEY_Y;
		io.KeyMap[ImGuiKey_Z]			= FR_KEY_Z;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach() {
		ImGui::DestroyContext();
	}

	void ImGuiLayer::OnUpdate() {
		
		ImGuiIO& io = ImGui::GetIO();
		
		float time = (float) glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool showDemo = true;
		ImGui::ShowDemoWindow(&showDemo);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& e) {

		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<MouseButtonPressedEvent>(FR_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressed));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(FR_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleased));
		dispatcher.Dispatch<MouseScrolledEvent>(FR_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolled));
		dispatcher.Dispatch<MouseMovedEvent>(FR_BIND_EVENT_FN(ImGuiLayer::OnMouseMoved));
		dispatcher.Dispatch<KeyPressedEvent>(FR_BIND_EVENT_FN(ImGuiLayer::OnKeyPressed));
		dispatcher.Dispatch<KeyReleasedEvent>(FR_BIND_EVENT_FN(ImGuiLayer::OnKeyReleased));
		dispatcher.Dispatch<KeyTypedEvent>(FR_BIND_EVENT_FN(ImGuiLayer::OnKeyTyped));
		dispatcher.Dispatch<WindowResizedEvent>(FR_BIND_EVENT_FN(ImGuiLayer::OnWindowResized));
	}

	bool ImGuiLayer::OnWindowResized(WindowResizedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2((float) e.GetWidth(), (float) e.GetHeight());
		glViewport(0, 0, e.GetWidth(), e.GetHeight());
		return false;
	}

	bool ImGuiLayer::OnKeyPressed(KeyPressedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = true;

		io.KeyCtrl = io.KeysDown[FR_KEY_LEFT_CONTROL] || io.KeysDown[FR_KEY_RIGHT_CONTROL];
		io.KeyAlt = io.KeysDown[FR_KEY_LEFT_ALT] || io.KeysDown[FR_KEY_RIGHT_ALT];
		io.KeyShift = io.KeysDown[FR_KEY_LEFT_SHIFT] || io.KeysDown[FR_KEY_RIGHT_SHIFT];
		io.KeySuper = io.KeysDown[FR_KEY_LEFT_SUPER] || io.KeysDown[FR_KEY_RIGHT_SUPER];

		return false;
	}

	bool ImGuiLayer::OnKeyReleased(KeyReleasedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = false;
		return false;
	}

	bool ImGuiLayer::OnKeyTyped(KeyTypedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.AddInputCharacter(e.GetKeyCode());
		return false;
	}

	bool ImGuiLayer::OnMouseButtonPressed(MouseButtonPressedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetButton()] = true;
		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleased(MouseButtonReleasedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetButton()] = false;
		return false;
	}

	bool ImGuiLayer::OnMouseScrolled(MouseScrolledEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += e.GetOffsetX();
		io.MouseWheel += e.GetOffsetY();
		return false;
	}

	bool ImGuiLayer::OnMouseMoved(MouseMovedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());
		return false;
	}
}