#include <catch2/catch.hpp>
#include <hm/utils/Color.h>
#include <string>

using namespace hm;

TEST_CASE("hm::Color", "[Utils]") {
  Color c(1, 2, 3, 4);
  Color c2(1, 2, 3);

  SECTION("Constructors") {
    REQUIRE(c.a == 4);
    REQUIRE(c2.b == 3);
  }

  SECTION("#rgb2hex()") {
    c = Color::white;
    REQUIRE(c.rgb2hex(true) == "#ffffff");
  }

  SECTION("Test hex value") {
    c = Color::white;
    REQUIRE(c.hex == 0xFFFFFF);
  }
}
