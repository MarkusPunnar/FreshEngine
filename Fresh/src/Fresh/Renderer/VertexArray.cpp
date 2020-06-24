#include "frpch.h"

#include "Fresh/Renderer/VertexArray.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"
#include "Fresh/Renderer/Renderer2D.h"

namespace Fresh {

	std::shared_ptr<VertexArray> VertexArray::Create() {

		switch (Renderer2D::GetAPI()) {
		case Fresh::RendererAPI::API::None:
			FR_CORE_ERROR("Renderer API of type None is not supported!");
			return nullptr;
		case Fresh::RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLVertexArray>();
		}
		FR_CORE_WARN("Unknown Renderer API!");
		return nullptr;

	}

}