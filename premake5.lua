workspace "Pretzel"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Pretzel"
	location "Pretzel"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PZ_PLATFORM_WINDOWS",
			"PZ_BUILD_DLL"
		}

		postbuildcommands{("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")}

	filter "configurations:Debug"
		defines "PZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PZ_DIST"
		optimize "On"




project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Pretzel/vendor/spdlog/include",
		"Pretzel/src"
	}
	
	links
	{
		"Pretzel"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PZ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PZ_DIST"
		optimize "On"

