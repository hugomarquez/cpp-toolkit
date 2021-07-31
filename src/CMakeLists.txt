add_subdirectory(utils)
add_subdirectory(math)
add_subdirectory(system)
add_subdirectory(sdl)

add_executable(main main.cpp)

# Local libs
# hm-sdl links publicly to system and utils, no need to relink again
#target_link_libraries(main hm-system)
#target_link_libraries(main hm-utils)

target_link_libraries(main PRIVATE hm-sdl)
