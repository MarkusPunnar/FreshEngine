#pragma once

#include "Core.h"

namespace Fresh {

	class FRESH_API FreshApplication {

	public:

		FreshApplication();
		virtual ~FreshApplication();

		void Run();
	};

	FreshApplication* CreateApplication();

}