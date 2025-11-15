BD ?= build

all:
	@echo "Linking & compiling.."
	@mkdir -p $(BD)/
	@clang -c module.c -o $(BD)/module.obj	
	@clang main.c $(BD)/module.obj -o $(BD)/program.exe
	@echo "Done!"

