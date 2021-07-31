#include <catch2/catch.hpp>
#include <hm/math/utils.h>

using namespace hm;

TEST_CASE("hm::utils", "[Math]") {
  float rad = 1.0472f; // 60 degrees
  float deg = 60.0f;

  SECTION("#isEqual(float a, float b)") {
    REQUIRE(isEqual(1.3, 1.3));
  }

  SECTION("#degrees(T radians)") {
    REQUIRE(isEqual(degrees(rad), deg));
  }

  SECTION("#radians(T degrees)") {
    REQUIRE(isEqual(radians(deg), rad));
  }

  SECTION("#max(T a, T b)") {
    REQUIRE(max(rad, deg) == deg);
  }

  SECTION("#min(T a, T b)") {
    REQUIRE(min(rad, deg) == rad);
  }

  SECTION("#abs(T a)") {
    int a = -10;
    float b = -10.0f;
    double c = -10.0f;
    REQUIRE(abs(a) == (a *  -1));
    REQUIRE(abs(b) == (b *  -1));
    REQUIRE(abs(c) == (c *  -1));
  }
  
  SECTION("#min(T value, T lower, T upper)") {
    REQUIRE(clamp(5, 3, 7) == 5);
    REQUIRE(clamp(17, 20, 50) == 20);
    REQUIRE(clamp(10, 0, 9) == 9);
  }

  SECTION("#lerp(float a, float b, float f)") {
    REQUIRE(isEqual(lerp(1, 3, 0), 1));
    REQUIRE(isEqual(lerp(1, 3, 1), 3));
  }

  SECTION("#plerp(float a, float b, float f)") {
    REQUIRE(isEqual(plerp(1, 3, 0), 1));
    REQUIRE(isEqual(plerp(1, 3, 1), 3));
  }
}
