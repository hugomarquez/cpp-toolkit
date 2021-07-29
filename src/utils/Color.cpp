#include "include/hm/utils/Color.h"

namespace hm {

  Color::Color(u8 r, u8 g, u8 b) : r(r), g(g), b(b)
  {
    a = 255;
    hex = (r << 16 | g << 8 | b);
  }

  Color::Color(u8 r, u8 g, u8 b, u8 a) : r(r), g(g), b(b), a(a)
  {
    hex = (r << 16 | g << 8 | b);
  }

  std::string Color::rgb2hex(bool hash=true)
  {
    std::stringstream ss;
    if (hash) { ss << "#"; }
    ss << std::hex << hex;
    return ss.str();
  }

  Color Color::primary    {0, 123, 255};
  Color Color::secondary  {108, 117, 125};
  Color Color::success    {40, 167, 69};
  Color Color::danger     {220, 53, 69};
  Color Color::warning    {255, 193, 7};
  Color Color::info       {23, 162, 184};
  Color Color::ligth      {248, 249, 250};
  Color Color::dark       {52, 58, 64};
  Color Color::white      {255, 255, 255};

}