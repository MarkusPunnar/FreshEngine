#pragma once

#ifdef FR_PLATFORM_WINDOWS

extern Fresh::Application* Fresh::CreateApplication();

int main(int argc, char* argv[]) {
	auto app = Fresh::CreateApplication();
	Fresh::Logger::Init();
	FR_CORE_INFO("Welcome to Fresh engine!");
	app->Run();
	delete app;
}

#endif 
