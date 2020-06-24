#pragma once

#include "Fresh/Renderer/VertexArray.h"

#include <glm/vec4.hpp>

namespace Fresh {

	class RendererAPI {

	public:

		enum class API {
			None = 0, OpenGL = 1
		};

	public:

		virtual void Init() = 0;

		virtual void SetClearColor(glm::vec4 color) = 0;

		virtual void Clear() = 0;

		virtual void Draw(const std::shared_ptr<VertexArray>& vertexArray) = 0;

		static std::unique_ptr<RendererAPI> Create();

		inline static API GetAPI() { return s_Api; };

	private:

		static API s_Api;
	};

}
