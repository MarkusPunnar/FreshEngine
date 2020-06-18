workspace "Fresh"
	architecture "x64"
	configurations 
	{
		"Debug", 
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include",
		"Fresh/src"
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

