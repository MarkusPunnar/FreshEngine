#pragma once

#include "Fresh/Renderer/RenderCommand.h"

namespace Fresh {

	class Renderer2D {

	public:

		static void Init();
		static void Shutdown();

		static void Prepare(glm::vec4 clearColor);
		 
		static void BeginScene();
		static void EndScene();

		static void Submit();


	private:

	};

}
