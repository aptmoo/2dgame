project "sokol"
    -- Input
    files
    {
        "%{wks.location}/ext/sokol/**.h",
        "%{wks.location}/ext/sokol/**.c"
    }

    includedirs
    {
        "%{wks.location}/ext/"
    }

    -- Linker
    links
    {

    }

    filter "system:linux"
        links { "dl", "m", "GL" }
        libdirs { "/usr/lib/" }

    -- Preprocessor
    
    -- Language
    language    "C"

    -- Output
    kind        "StaticLib"
    targetdir   "%{wks.location}/lib/"
    objdir      "%{wks.location}/bin-int/"

project "glfw"
    -- Input
    files
    {
        "./glfw/**.h",
        "./glfw/src/**.c"
    }

    -- Linker
    links { }

    -- Preprocessor
    filter "system:linux"
        defines { "_GLFW_X11" }
        libdirs { "/usr/lib/ "}

    -- filter "system:windows"
    --     defines { "_GLFW_WIN32" }

    -- Language
    language "C"

    -- Output
    kind        "StaticLib"
    targetdir   "%{wks.location}/lib/"
    objdir      "%{wks.location}/bin-int/"

    -- Configs
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
  
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    -- Output
    kind        "StaticLib"
    targetdir   "%{wks.location}/lib/"
    objdir      "%{wks.location}/bin-int/"