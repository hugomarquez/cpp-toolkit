add_library(hm-math SHARED Random.cpp)

target_include_directories(hm-math 
  PUBLIC include
  PRIVATE .
)

target_link_libraries(hm-math 
  PUBLIC hm-utils
)