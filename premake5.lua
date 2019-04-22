workspace "Tube"

    architecture "x64"

    configurations{
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Tube/vendor/GLFW/include"

include "Tube/vendor/GLFW"

project "Tube"
    location "Tube"
    kind "SharedLib"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "tbpch.h"
    pchsource "Tube/src/tbpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}"
    }

    links{
        "GLFW",
        "opengl32.lib"
    }


    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "TB_PLATFORM_WINDOWS", 
            "TB_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

        filter "configurations:Debug"
            defines "TB_DEBUG"
            symbols "On"
            
        filter "configurations:Release"
        defines "TB_RELEASE"
        symbols "On"

        filter "configurations:Dist"
        defines "TB_DIST"
        optimize "On"
        architecture "x64"

        configurations{
            "Debug",
            "Release",
            "Dist"
        }
    
    
project "Sandbox"

    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    
    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")
   
    files
    {
       "%{prj.name}/src/**.h",
       "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "Tube/vendor/spdlog/include",
        "Tube/src"
    }

    links
    {
        "Tube"
    }
    
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
    
        defines
        {
            "TB_PLATFORM_WINDOWS", 
        }

    filter "configurations:Debug"
        defines "TB_DEBUG"
        symbols "On"
            
    filter "configurations:Release"
        defines "TB_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "TB_DIST"
        optimize "On"
        architecture "x64"
