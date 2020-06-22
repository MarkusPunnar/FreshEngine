#include "frpch.h"

#include "Platform/OpenGL/OpenGLContext.h"

#include <glad/glad.h>

namespace Fresh {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle) {};

	void OpenGLContext::Init() {
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		if (status == 0) {
			FR_CORE_ERROR("Failed to initialize Glad!");
		}
	}

	void OpenGLContext::SwapBuffers() {
		glfwPollEvents();
		glfwSwapBuffers(m_WindowHandle);
	}
}