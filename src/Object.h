#pragma once

#include "Renderer/Color.h"
#include "math/Vector.h"
#include "surface/Surface.h"

class Sphere : public Surface {
 public:
  Sphere(const Vec3& center, float radius, const Color& color)
      : m_center(center), m_radius(radius), Surface(color){};
  HitRecord hit(Ray r, float t0, float t1) override;

 private:
  Vec3 m_center;
  float m_radius;
};