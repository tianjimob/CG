#include "Surface.h"

#include <limits>
#include <memory>

HitRecord GroupSurface::hit(Ray r, float t0, float t1) {
  HitRecord closestHit{.t = std::numeric_limits<float>::infinity(),
                       .color = {1.0f, 1.0f, 1.0f},
                       .normal = {0.0f, 0.0f, 0.0f}};
  for (const auto& surface : m_surfaces) {
    HitRecord record = surface->hit(r, t0, t1);
    if (record.t < std::numeric_limits<float>::infinity()) {
      closestHit = record;
      closestHit.color = record.color;
      t1 = closestHit.t;
    }
  }
  return closestHit;
}
