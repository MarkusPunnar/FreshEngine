#include "frpch.h"

#include "Fresh/Renderer/RenderCommand.h"

namespace Fresh {

	std::unique_ptr<RendererAPI> RenderCommand::s_Api = RendererAPI::Create();

}