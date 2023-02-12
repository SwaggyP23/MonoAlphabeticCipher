workspace "MonoAlphabeticCipher"
    architecture "x86_64"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.architecture}-%{cfg.buildcfg}"

group "Core"
    include "MonoAlphabeticCipher"
group ""