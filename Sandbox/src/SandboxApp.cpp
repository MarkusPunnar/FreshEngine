#include <Fresh.h>

class SandboxApp : public Fresh::FreshApplication {

public:
	SandboxApp() {}

	~SandboxApp() {}
};

Fresh::FreshApplication* Fresh::CreateApplication() {
	return new SandboxApp();
}