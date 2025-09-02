#pragma once
#include <string>

namespace ecs
{
struct Position
{
  float x, y;
};

struct Sprite
{
  std::string texturePath;
  float width, height;
};
}  // namespace ecs