#include <string>
#include <catch2/catch.hpp>
#include <hm/system/File.h>

using namespace hm;

TEST_CASE("hm::File", "[System]") {
  std::string base = "add-path";
  std::string path = "test/CMakeLists.txt";
  std::string full_path = base + path;
  
  File::base_path = base;
  File f(path);

  SECTION("#getPath()") {
    REQUIRE(f.getPath() == full_path);
  }
  
  SECTION("#getFileName()") {
    REQUIRE(f.getFileName() == "CMakeLists.txt");
  }

  SECTION("#getExtension()") {
    REQUIRE(f.getExtension() == ".txt");
  }

  SECTION("#getFileNameNoExtension()") {
    REQUIRE(f.getFileNameNoExtension() == "CMakeLists");
  }
}
