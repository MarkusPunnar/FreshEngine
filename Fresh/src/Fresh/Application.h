#pragma once

#include "Core.h"

namespace Fresh {
	
	class Application {

	public:

		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}