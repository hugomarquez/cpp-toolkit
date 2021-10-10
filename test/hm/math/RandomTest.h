#include <string>
#include <type_traits>
#include <stdint.h>

#include <catch2/catch.hpp>
#include <hm/math/Random.h>

using namespace hm;

TEST_CASE("hm::random", "[Math]") {
  Random *r = Random::getInstance();

  SECTION("#intRange()") {
    int r1 = r->intRange(1, 50);
    int r2 = r->intRange(1, 50);
    REQUIRE(r1 != r2);
  }

  SECTION("#u32()") {
    uint32_t r1 = *r;
    uint32_t r2 = *r;
    REQUIRE(typeid(r1) == typeid(uint32_t));
    REQUIRE(r1 != r2);
  }

  SECTION("#u16()") {
    uint16_t r1 = *r;
    uint16_t r2 = *r;
    REQUIRE(typeid(r1) == typeid(uint16_t));
    REQUIRE(r1 != r2);
  }

  SECTION("#int()") {
    int r1 = *r;
    int r2 = *r;
    REQUIRE(typeid(r1) == typeid(int));
    REQUIRE(r1 != r2);
  }

  SECTION("#float()") {
    float r1 = *r;
    float r2 = *r;
    REQUIRE(typeid(r1) == typeid(float));
    REQUIRE(r1 != r2);
  }
}
