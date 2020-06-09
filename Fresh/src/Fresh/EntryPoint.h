#pragma once


#ifdef FRESH_PLATFORM_WINDOWS

extern Fresh::FreshApplication* Fresh::CreateApplication();

int main(int argc, char** argv) {
	auto app = Fresh::CreateApplication();
	app->Run();
	delete app;
}

#endif 
