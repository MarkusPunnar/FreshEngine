#include <Fresh.h>


class TestLayer : public Fresh::Layer {

	void OnUpdate() override {
		
	}

	void OnEvent(Fresh::Event& e) override {
		
	}

	void OnAttach() override {
		
	}

	void OnDetach() override {
		
	}

};

class SandboxApp : public Fresh::Application {

public:
	SandboxApp() {
		PushLayer(new TestLayer());
		PushOverlay(new Fresh::ImGuiLayer());
	}

	~SandboxApp() {}
};


Fresh::Application* Fresh::CreateApplication() {
	return new SandboxApp();
}