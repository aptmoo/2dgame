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
        "src/",
        "ext/sokol/",
        "ext/glfw/include/"
    }

    -- Linker
    links
    {
        "glfw", "sokol"
    }

    libdirs { "./lib/" }

    filter "system:linux"
        links { "dl", "m", "GL" }
        libdirs { "/usr/lib/" }
    
    -- Language
    language    "C"
    cdialect    "C17"

    -- Output
    kind        "ConsoleApp"
    targetname  "2dgame.out"
    targetdir   "./bin/"
    objdir      "./bin-int/"

project "glfw"
    -- Input
    files
    {
        "ext/glfw/**.h",
        "ext/glfw/src/**.c"
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

    -- Preprocessor

    filter "system:linux"
        defines { "_GLFW_X11" }
    
    -- Language
    language    "C"

    -- Output
    kind        "StaticLib"
    targetdir   "./lib/"
    objdir      "./bin-int/"

project "sokol"
    -- Input
    files
    {
        "ext/sokol/**.h",
        "ext/sokol/**.c"
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
        links { "dl", "m", "GL" }
        libdirs { "/usr/lib/" }

    -- Preprocessor

    filter "system:linux"
        defines { "_GLFW_X11" }
    
    -- Language
    language    "C"

    -- Output
    kind        "StaticLib"
    targetdir   "./lib/"
    objdir      "./bin-int/"