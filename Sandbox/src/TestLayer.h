#pragma once

#include <memory>

#include "Fresh/Core/Layer.h"
#include "Fresh/Renderer/VertexArray.h"
#include "Fresh/Renderer/Buffer.h"
#include "Fresh/Events/Event.h"

class TestLayer : public Fresh::Layer {

public:
	TestLayer();

	void OnUpdate() override;

	void OnEvent(Fresh::Event& e) override;

	void OnAttach() override;

	void OnDetach() override;

private:
	std::shared_ptr<Fresh::VertexArray> m_VertexArray;
	std::shared_ptr<Fresh::VertexBuffer> m_VertexBuffer;
	std::shared_ptr<Fresh::IndexBuffer> m_IndexBuffer;

};
