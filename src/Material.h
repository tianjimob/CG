#pragma once

#include "Renderer/Color.h"
#include "math/Vector.h"

class Material {
 public:
  Color color;

  explicit Material(const Color& color) : color(color) {}
  Color evaluate(Vec3 l, Vec3 u, Vec3 n) { /*@todo: should fill */
    return {0.0f, 0.0f, 0.0f};
  }
};