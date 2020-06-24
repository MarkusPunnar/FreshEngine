#pragma once

#include "Fresh/Renderer/VertexArray.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

#include <vector>

namespace Fresh {

	class OpenGLVertexArray : public VertexArray {

	public:

		OpenGLVertexArray();
		~OpenGLVertexArray() = default;

		void Bind() const override;
		void Unbind() const override;

		void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;

		inline void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) { m_IndexBuffer = indexBuffer; }
		

		inline const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }
		inline const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const { return m_VertexBuffers; }

	private:

		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;

		uint32_t m_VertexArrayID;

	};

}