#pragma once

#include <glm/vec4.hpp>

namespace Fresh {

	class RendererAPI {

		enum class API {
			None = 0, OpenGL = 1
		};

	public:

		virtual void Init() = 0;

		virtual void SetClearColor(glm::vec4 color) = 0;

		virtual void Clear() = 0;

		virtual void Draw() = 0;

		static std::unique_ptr<RendererAPI> Create();

	private:

		static API s_Api;
	};

}
