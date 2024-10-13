workspace "Corylium"
	architecture "x86_64"
	
	configurations 
	{ 
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Corylium"
	location "Corylium"
	kind "SharedLib"
    language "C++"
	
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	pchheader "crlypch.h"
	pchsource "%{prj.name}/src/crlypch.cpp"

    files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp" 
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/3rdparties/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"CRLY_PLATFORM_WINDOWS",
			"CRLY_BUILD_DLL",
			"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} %{wks.location}bin/" .. outputdir .. "/Sandbox")
		}
		
    filter "configurations:Debug"
		defines "CRLY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CRLY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CRLY_DIST"
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
		"Corylium/3rdparties/spdlog/include",
		"Corylium/src"
	}
	
	links
	{
		"Corylium"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"CRLY_PLATFORM_WINDOWS"
		}
		postbuildcommands
		{
			("{COPY} %{wks.location}bin/" .. outputdir .. "/Corylium/Corylium.dll %{wks.location}bin/" .. outputdir .. "/%{prj.name}")
		}
		
    filter "configurations:Debug"
		defines "CRLY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CRLY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CRLY_DIST"
		optimize "On"

