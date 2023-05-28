workspace "2dgame"
    configurations { "Debug", "Release" }

project "game"
    -- Input
    files
    {
        "src/**.h", "src/**.c"
    }

    includedirs
    {
        "src/"
    }

    -- Linker
    links
    {

    }

    filter "system:linux"
        links { "dl", "m" }
        libdirs { "/usr/lib/" }
    
    -- Language
    language    "C"
    cdialect    "C17"

    -- Output
    kind        "ConsoleApp"
    targetname  "2dgame.out"
    targetdir   "./bin/"
    objdir      "./bin-int/"