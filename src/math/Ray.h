#pragma once

#include "math/Vector.h"
struct Ray {
  Vec3 origin;
  Vec3 direction;

  inline Vec3 evaluate(float t) const { return origin + t * direction; }
  static Ray genOrthographicRay(float left, float right, float bottom,
                                float top, int width, int height, int i, int j);
  static Ray genPerspectiveRay(float left, float right, float bottom, float top,
                               float distance, int width, int height, int i,
                               int j);
};
