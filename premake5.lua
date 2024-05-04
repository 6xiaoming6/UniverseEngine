--workspace���ǽ������
workspace "UniverseEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir  = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
--project���Ǿ�����һ����Ŀ
project "UniverseEngine"
	location "UniverseEngine"--��Ŀ�����·��Ŀ¼
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")--���ն������ļ����Ŀ¼
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")--�м��ļ�Ŀ¼
	--��Ŀ�ڰ������ļ�
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	--����������Ŀ��������������Ż���Ч����
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
	location "Sandbox"--��Ŀ�����·��Ŀ¼
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")--���ն������ļ����Ŀ¼
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")--�м��ļ�Ŀ¼
	--��Ŀ�ڰ������ļ�
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

	--����������Ŀ��������������Ż���Ч����
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