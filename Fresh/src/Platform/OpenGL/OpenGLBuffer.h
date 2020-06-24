#pragma once

#include "Fresh/Renderer/Buffer.h"

namespace Fresh {

	class OpenGLVertexBuffer : public VertexBuffer {

	public:
		
		OpenGLVertexBuffer(float* data, uint32_t size);
		~OpenGLVertexBuffer() = default;

		void Bind() const override;
		void Unbind() const override;

	private:
		uint32_t m_BufferID;

	};

	class OpenGLIndexBuffer : public IndexBuffer {

	public:

		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		~OpenGLIndexBuffer() = default;

		void Bind() const override;
		void Unbind() const override;
		inline uint32_t GetCount() const { return m_Count; }

	private:
		uint32_t m_BufferID;
		uint32_t m_Count;
	};
}