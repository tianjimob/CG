#pragma once

#include <memory>
#include <vector>

#include "Material.h"
#include "Renderer/Color.h"
#include "math/Ray.h"
#include "math/Vector.h"


class HitRecord;

class Surface {
 public:
  explicit Surface(Material material) : m_material(material) {}
  Material& getMaterial() { return m_material; }
  virtual ~Surface() = default;
  virtual HitRecord hit(const Ray& r, float t0, float t1) = 0;

 private:
  Material m_material;
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
  inline void add(std::shared_ptr<Surface> surface) {
    m_surfaces.push_back(surface);
  }

 private:
  std::vector<std::shared_ptr<Surface>> m_surfaces;
};