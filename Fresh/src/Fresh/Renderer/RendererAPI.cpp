#include "frpch.h"

#include "Fresh/Renderer/RendererAPI.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Fresh {

	RendererAPI::API RendererAPI::s_Api = RendererAPI::API::OpenGL;

	std::unique_ptr<RendererAPI> RendererAPI::Create() {
		switch (s_Api)
		{
		case Fresh::RendererAPI::API::None:
			FR_CORE_ERROR("Renderer API of type None is not supported!");
			return nullptr;
		case Fresh::RendererAPI::API::OpenGL:
			return std::make_unique<OpenGLRendererAPI>();
		}
		FR_CORE_WARN("Unknown Renderer API!");
		return nullptr;
	}

}