#include <Fresh.h>

class SandboxApp : public Fresh::Application {

public:
	SandboxApp() {}

	~SandboxApp() {}
};

Fresh::Application* Fresh::CreateApplication() {
	return new SandboxApp();
}