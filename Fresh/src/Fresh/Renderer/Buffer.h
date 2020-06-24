#pragma once

#include <memory>

namespace Fresh {

	class VertexBuffer {

	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		
		//Set data
		//Get/Set layout

		static std::shared_ptr<VertexBuffer> Create(float* data, uint32_t size);

	};

	class IndexBuffer {

	public:

		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual uint32_t GetCount() const = 0;

		static std::shared_ptr<IndexBuffer> Create(uint32_t* indices, uint32_t count);
	};

}