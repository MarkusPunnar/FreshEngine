#include <Fresh.h>

#include "TestLayer.h"

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