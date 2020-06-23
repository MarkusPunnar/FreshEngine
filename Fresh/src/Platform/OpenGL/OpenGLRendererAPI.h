#pragma once

#include "Fresh/Renderer/RendererAPI.h"

namespace Fresh {

	class OpenGLRendererAPI : public RendererAPI {

	public:

		void Init() override;

		void SetClearColor(glm::vec4 color) override;

		void Clear() override;

		void Draw() override;

	};

}
