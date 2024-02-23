workspace "Jiggle"
    architecture "x64"
	startproject "SpringBox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SpringBox"
    location "SpringBox"
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
        "Jiggle/vendor/spdlog/include", -- Corrected relative path
        "Jiggle/src" -- Corrected relative path
    }

    links 
    {
        "Jiggle"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "JIGL_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "JIGL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "JIGL_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "JIGL_DIST"
        optimize "On"


project "Jiggle"
    location "Jiggle"
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
        "Jiggle/vendor/spdlog/include" -- Relative path to the include directory
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "JIGL_PLATFORM_WINDOWS",
            "JIGL_BUILD_DLL" -- Removed semicolon
        }

		postbuildcommands
		{
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SpringBox"
		}

    filter "configurations:Debug"
        defines "JIGL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "JIGL_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "JIGL_DIST"
        optimize "On"