project "MonoAlphabeticCipher"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin/Intermediates/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp",
    }

    includedirs
    {
        "src",
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines "CIPHER_RD_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "CIPHER_RD_RELEASE"
        runtime "Release"
        optimize "Speed"
        inlining "Auto"