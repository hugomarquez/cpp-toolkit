add_library(hm-system SHARED 
  File.cpp 
  Logger.cpp
  Platform.cpp
)

# Find Boost
find_package(Boost REQUIRED COMPONENTS filesystem)
if(Boost_FOUND)
  message(STATUS "[SYSTEM][BUILD]: Required library Boost found!")
  target_link_libraries(hm-system PRIVATE Boost::filesystem)
endif(Boost_FOUND)

# Find spdlog
find_package(spdlog REQUIRED)
if(spdlog_FOUND)
  message(STATUS "[SYSTEM][BUILD]: Required library spdlog found!")
  target_link_libraries(hm-system PRIVATE spdlog::spdlog)
endif(spdlog_FOUND)

target_include_directories(hm-system 
  PUBLIC include
  PRIVATE .
)