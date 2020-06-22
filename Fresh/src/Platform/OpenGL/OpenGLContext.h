#pragma once

#include "Fresh/Renderer/GraphicsContext.h"

#include "GLFW/glfw3.h"

namespace Fresh {

	class OpenGLContext : public GraphicsContext {

	public:

		OpenGLContext(GLFWwindow* windowHandle);
		~OpenGLContext() = default;

		void Init() override;
		void SwapBuffers() override;

	private:
		GLFWwindow* m_WindowHandle;

	};

}