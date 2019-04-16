# OOS1

"Objektorientierte Systeme 1" exercises for OOS1 class at University of Esslingen.

## Tools

* [cmake](https://cmake.org/) - generating native build environment (Makefiles, VisualStudio Solution, Eclipse project, etc.)
* [vscode](https://code.visualstudio.com/) - editing and inspecting code -- _optional_

## Building

1. Clone or download the sources from [GitHub](https://github.com/FreeGeronimo/OOS1).
2. `cd` into the project root folder.
3. Run `mkdir -p ./_build && cd ./_build` to create a build-folder and change into it.
4. Create your native build environment by running `cmake ..`, where `..` should be the project root folder.
5. Build the project using your native build environment (Makefile, VisualStudio Solution, Eclipse project etc.). Alternativly try running `cmake --build . --target all` to let cmake invoke your native build environment.
