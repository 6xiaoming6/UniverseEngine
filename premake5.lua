--workspace就是解决方案
workspace "UniverseEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir  = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
--project就是具体哪一个项目
project "UniverseEngine"
	location "UniverseEngine"--项目的相对路径目录
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")--最终二进制文件输出目录
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")--中间文件目录
	--项目内包含的文件
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	--过滤器，项目满足过滤器条件才会生效配置
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"UN_BUILD_DLL",
			"UN_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "UN_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "UN_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "UN_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"--项目的相对路径目录
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")--最终二进制文件输出目录
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")--中间文件目录
	--项目内包含的文件
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"UniverseEngine/vendor/spdlog/include",
		"UniverseEngine/src"
	}

	links
	{
		"UniverseEngine"
	}

	--过滤器，项目满足过滤器条件才会生效配置
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"UN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "UN_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "UN_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "UN_DIST"
		optimize "On"