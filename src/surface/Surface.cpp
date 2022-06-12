#include "Surface.h"

#include <limits>
#include <memory>

HitRecord GroupSurface::hit(Ray r, float t0, float t1) const {
  HitRecord closestHit{.t = std::numeric_limits<float>::infinity(),
                       .normal = {0.0f, 0.0f, 0.0f}};
  for (const auto& surface : m_surfaces) {
    HitRecord record = surface->hit(r, t0, t1);
    if (record.t < std::numeric_limits<float>::infinity()) {
      closestHit = record;
      t1 = closestHit.t;
    }
  }
  return closestHit;
}
