#pragma once

#include "Renderer/Color.h"
#include "math/Vector.h"
#include "surface/Surface.h"

class Sphere : public Surface {
 public:
  Sphere(const Vec3& center, float radius,
         const Color& color = {1.0f, 1.0f, 1.0f});
  HitRecord hit(Ray r, float t0, float t1) override;

 private:
  Vec3 m_center;
  float m_radius;
  Color m_color;
};