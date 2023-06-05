# GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  glfw_config = debug
  sokol_config = debug
  game_config = debug
endif
ifeq ($(config),release)
  glfw_config = release
  sokol_config = release
  game_config = release
endif

PROJECTS := glfw sokol game

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

glfw:
ifneq (,$(glfw_config))
	@echo "==== Building glfw ($(glfw_config)) ===="
	@${MAKE} --no-print-directory -C . -f glfw.make config=$(glfw_config)
endif

sokol:
ifneq (,$(sokol_config))
	@echo "==== Building sokol ($(sokol_config)) ===="
	@${MAKE} --no-print-directory -C . -f sokol.make config=$(sokol_config)
endif

game: glfw sokol
ifneq (,$(game_config))
	@echo "==== Building game ($(game_config)) ===="
	@${MAKE} --no-print-directory -C . -f game.make config=$(game_config)
endif

clean:
	@${MAKE} --no-print-directory -C . -f glfw.make clean
	@${MAKE} --no-print-directory -C . -f sokol.make clean
	@${MAKE} --no-print-directory -C . -f game.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   glfw"
	@echo "   sokol"
	@echo "   game"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"