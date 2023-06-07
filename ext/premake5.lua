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

    filter "system:linux"
        defines { "_GLFW_X11" }
    
    -- Language
    language    "C"

    -- Output
    kind        "StaticLib"
    targetdir   "%{wks.location}/lib/"
    objdir      "%{wks.location}/bin-int/"