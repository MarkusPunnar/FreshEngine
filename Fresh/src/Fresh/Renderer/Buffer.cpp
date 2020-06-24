#include "frpch.h"

#include "Fresh/Renderer/Buffer.h"
#include "Fresh/Renderer/Renderer2D.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Fresh {

	std::shared_ptr<VertexBuffer> VertexBuffer::Create(float* data, uint32_t size) {

		switch (Renderer2D::GetAPI()) {
		case Fresh::RendererAPI::API::None:
			FR_CORE_ERROR("Renderer API of type None is not supported!");
			return nullptr;
		case Fresh::RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLVertexBuffer>(data, size);
		}
		FR_CORE_WARN("Unknown Renderer API!");
		return nullptr;

	}

	std::shared_ptr<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count) {

		switch (Renderer2D::GetAPI()) {
		case Fresh::RendererAPI::API::None:
			FR_CORE_ERROR("Renderer API of type None is not supported!");
			return nullptr;
		case Fresh::RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLIndexBuffer>(indices, count);
		}
		FR_CORE_WARN("Unknown Renderer API!");
		return nullptr;

	}

}