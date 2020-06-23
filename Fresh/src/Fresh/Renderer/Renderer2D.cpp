#include "frpch.h"

#include "Fresh/Renderer/Renderer2D.h"

namespace Fresh {

	void Renderer2D::Init() {
		RenderCommand::Init();
	}

	void Renderer2D::Shutdown() {
		
	}

	void Renderer2D::Prepare(glm::vec4 clearColor) {
		RenderCommand::ClearColor(clearColor);
		RenderCommand::Clear();
	}

	void Renderer2D::BeginScene() {

	}

	void Renderer2D::EndScene() {

	}

	void Renderer2D::Submit() {
		RenderCommand::Draw();
	}

}