#pragma once

#include <string>
#include <memory>

namespace Fresh {

	class Shader {

	public:
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		static std::shared_ptr<Shader> Create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};

}
