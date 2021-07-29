#include <string>
#include <catch2/catch.hpp>
#include <hm/system/Platform.h>

using namespace hm;

TEST_CASE("hm::Platform", "[System]") {
  SECTION("#getPlatform()") {
    REQUIRE(Platform::getPlatform() == "Linux");
    // On Windows
    //REQUIRE(Platform::getPlatform() == "Windows64");
    //REQUIRE(Platform::getPlatform() == "Windows32");
    
    // On OSX
    //REQUIRE(Platform::getPlatform() == "MacOS");
  }
}
