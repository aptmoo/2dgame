project "game"
    -- Input
    files
    {
        "%{wks.location}/src/**.h", "%{wks.location}/src/**.c"
    }

    includedirs
    {
        "%{wks.location}/src/",
        "%{wks.location}/ext/sokol/",
        "%{wks.location}/ext/glfw/include/"
    }

    -- Linker
    links
    {
        "glfw", "sokol"
    }

    libdirs { "%{wks.location}/lib/" }

    filter "system:linux"
        links { "dl", "m", "GL" }
        libdirs { "/usr/lib/" }
    
    -- Language
    language    "C"
    cdialect    "C17"

    -- Output
    kind        "ConsoleApp"
    targetname  "2dgame.out"
    targetdir   "%{wks.location}/bin/"
    objdir      "%{wks.location}/bin-int/"