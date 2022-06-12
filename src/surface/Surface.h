#pragma once

#include <memory>
#include <vector>

#include "Material.h"
#include "Ray.h"
#include "Renderer/Color.h"
#include "math/Vector.h"

class HitRecord;

class Surface {
 public:
  Material material;

  Surface(Color color) : material(color) {}
  virtual ~Surface() = default;
  virtual HitRecord hit(Ray r, float t0, float t1) = 0;
};

struct HitRecord {
  std::shared_ptr<Surface> surface;
  float t;  // coordinate of hit point along the ray, miss if t ==
            // std::numeric_limits<float>::infinity()
  Vec3 normal;
};

class GroupSurface {
 public:
  HitRecord hit(Ray r, float t0, float t1) const;
  // order adding is order rendering
  inline void add(std::shared_ptr<Surface> surface) {
    m_surfaces.push_back(surface);
  }

 private:
  std::vector<std::shared_ptr<Surface>> m_surfaces;
};