#include "TestLayer.h"

#include "Fresh/Renderer/Renderer2D.h"

TestLayer::TestLayer() {

}

void TestLayer::OnAttach() {

	float vertices[3 * 4] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.5f, 0.5f, 0.0f,
			-0.5f, 0.5f, 0.0f
	};

	uint32_t indices[6] = {
		0, 1, 2, 2, 3, 0
	};

	m_VertexArray = Fresh::VertexArray::Create();
	m_VertexBuffer = Fresh::VertexBuffer::Create(vertices, sizeof(vertices));
	m_VertexArray->AddVertexBuffer(m_VertexBuffer);
	m_IndexBuffer = Fresh::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
	m_VertexArray->SetIndexBuffer(m_IndexBuffer);
}

void TestLayer::OnDetach() {

}

void TestLayer::OnUpdate() {
	Fresh::Renderer2D::Prepare({ 0.2f, 0.3f, 0.8f, 1.0f });
	Fresh::Renderer2D::BeginScene();
	Fresh::Renderer2D::Submit(m_VertexArray);
	Fresh::Renderer2D::EndScene();
}

void TestLayer::OnEvent(Fresh::Event& e) {

}