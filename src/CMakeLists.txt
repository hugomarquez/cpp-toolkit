add_subdirectory(utils)
add_subdirectory(system)
add_subdirectory(math)

add_subdirectory(sdl)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE hm-sdl)