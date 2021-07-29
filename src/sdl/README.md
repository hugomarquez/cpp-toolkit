# SDL Abstraction
## Notes on dependencies
SDL2 is not currently available for linux through the conan center,
so it is needed to install the following libraries into the machine
using the package manager:

```bash
# install sdl2
sudo apt install libsdl2-dev libsdl2-2.0-0 -y;

# install sdl image  - if you want to display images
sudo apt install libjpeg-dev libwebp-dev libtiff5-dev libsdl2-image-dev libsdl2-image-2.0-0 -y;

# install sdl mixer  - if you want sound
sudo apt install libmikmod-dev libfishsound1-dev libsmpeg-dev liboggz2-dev libflac-dev libfluidsynth-dev libsdl2-mixer-dev libsdl2-mixer-2.0-0 -y;

# install sdl true type fonts - if you want to use text
sudo apt install libfreetype6-dev libsdl2-ttf-dev libsdl2-ttf-2.0-0 -y;
```

Use:

```bash
`sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
```

To link them, for example

```bash
g++ myProgram.cpp -o myProgram `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
```

## Notes on CMAKE
Include SDL2 to our project with cmake, first install via package manager, then:

```cmake
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
.
...
.
target_link_libraries(target ${SDL2_LIBRARIES})
```

- reference: [cmake-sdl2-image-cmake](https://trenki2.github.io/blog/2017/07/04/using-sdl2-image-with-cmake/)