set(hm-srcs 
  Application.cpp
  AssetManager.cpp
  Rectangle.cpp
  Renderer.cpp
  Texture.cpp
  Timer.cpp
  Window.cpp
)

add_library(hm-sdl SHARED ${hm-srcs})

# Find SDL2
find_package(SDL2 REQUIRED)
if(SDL2_FOUND)
  message(STATUS "[BUILD]: Required library SDL2 found!")

  find_package(SDL2_image REQUIRED)
  message(STATUS "[BUILD]: Required library SDL2_image found!")

  target_include_directories(hm-sdl PUBLIC ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
  target_link_libraries(hm-sdl PUBLIC ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
endif(SDL2_FOUND)

target_include_directories(hm-sdl PUBLIC ${CMAKE_SOURCE_DIR}/src/sdl/)

target_link_libraries(hm-sdl 
  PUBLIC hm-utils
  PUBLIC hm-system
)