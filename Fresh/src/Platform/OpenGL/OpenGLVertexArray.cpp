#include "frpch.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

#include <glad/glad.h>

namespace Fresh {

	OpenGLVertexArray::OpenGLVertexArray() {
		glGenVertexArrays(1, &m_VertexArrayID);
	}

	void OpenGLVertexArray::Bind() const {
		glBindVertexArray(m_VertexArrayID);
	}

	void OpenGLVertexArray::Unbind() const {
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) {
		this->Bind();
		vertexBuffer->Bind();
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
		m_VertexBuffers.push_back(vertexBuffer);
	}
}