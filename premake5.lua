workspace "Fresh"
	architecture "x64"
	startproject "Sandbox"
	configurations 
	{
		"Debug", 
		"Release"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

includeDirs = {}
includeDirs["GLFW"] = "Fresh/vendor/GLFW/include"
includeDirs["Glad"] = "Fresh/vendor/Glad/include"
includeDirs["ImGui"] = "Fresh/vendor/imgui"
includeDirs["glm"] = "Fresh/vendor/glm"

group "dependencies"
	include "Fresh/vendor/GLFW"
	include "Fresh/vendor/Glad"
	include "Fresh/vendor/imgui"
group ""

project "Fresh"
	location "Fresh"
	kind "StaticLib"
	language "C++" 
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "frpch.h"
	pchsource "Fresh/src/frpch.cpp"

	files { 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include",
		"%{includeDirs.GLFW}",
		"%{includeDirs.Glad}",
		"%{includeDirs.ImGui}",
		"%{includeDirs.glm}",
		"Fresh/src"
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"FR_PLATFORM_WINDOWS",
			"FR_BUILD_DLL"
		}

		postbuildcommands {
			"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
		}

	filter "configurations:Debug"
      defines { 
		"DEBUG",
		"FR_DEBUG"
	  }
      symbols "On"

   filter "configurations:Release"
      defines { 
		"NDEBUG",
		"FR_RELEASE"
	  }

      optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files { 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{wks.name}/vendor/spdlog/include",
		"%{includeDirs.glm}",
		"Fresh/src"
	}

	links {
		"Fresh"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"FR_PLATFORM_WINDOWS"
		}
		

	filter "configurations:Debug"
      defines { 
		"DEBUG",
		"FR_DEBUG"
	  }
      symbols "On"

   filter "configurations:Release"
      defines { 
		"NDEBUG",
		"FR_RELEASE"
	  }

      optimize "On"

