add_library(hm-utils SHARED Color.cpp)

target_include_directories(hm-utils 
  PUBLIC include
  PRIVATE .
)