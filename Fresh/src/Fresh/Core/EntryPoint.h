#pragma once

#ifdef FR_PLATFORM_WINDOWS

extern Fresh::Application* Fresh::CreateApplication();

int main(int argc, char* argv[]) {
	Fresh::Logger::Init();
	auto app = Fresh::CreateApplication();
	FR_CORE_INFO("Welcome to Fresh engine!");
	app->Run();
	delete app;
}

#endif 
