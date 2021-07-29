# Enable testing
enable_testing()

# Find required package/framework for testing
find_package(Catch2 REQUIRED)

# Create main test executable
add_executable(mainTest mainTest.cpp)

# Link with hm-system library
target_link_libraries(mainTest hm-system)

# Link with hm-utils library
target_link_libraries(mainTest hm-utils)

# Link with Catch2 testing framework
if(Catch2_FOUND)
  message("-- [TEST]: Required library Catch2 found!")
  target_link_libraries(mainTest Catch2::Catch2)
  # include(Catch)
  # catch_discover_tests(mainTest)
endif(Catch2_FOUND)
