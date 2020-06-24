#pragma once

#include "RendererAPI.h"

#include <memory>

#include <glm/vec4.hpp>

namespace Fresh {

	class RenderCommand {

	public:

		static void Init() {
			s_Api->Init();
		}
		
		static void ClearColor(glm::vec4 color) {
			s_Api->SetClearColor(color);
		}

		static void Clear() {
			s_Api->Clear();
		}

		static void Draw(const std::shared_ptr<VertexArray>& vertexArray) {
			s_Api->Draw(vertexArray);
		}

	private:
		
		static std::unique_ptr<RendererAPI> s_Api;

	};

}
