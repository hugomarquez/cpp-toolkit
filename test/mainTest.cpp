// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

// Include the layers to test
#include "./hm/system/FileTest.h"
#include "./hm/system/PlatformTest.h"
#include "./hm/utils/ColorTest.h"
