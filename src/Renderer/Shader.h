#pragma once

#include <limits>

#include "Ray.h"
#include "Renderer/Color.h"
#include "Scene.h"
#include "surface/Surface.h"

class Shader {
 public:
  explicit Shader(Color bg) : m_bgColor(bg) {}
  inline Color shadeRay(const Ray& ray, float t0, float t1,
                        const Scene& scene) const {
    HitRecord record = scene.surfaces.hit(ray, t0, t1);
    if (record.t < std::numeric_limits<float>::infinity()) {
      //   Color c{0.0f, 0.0f, 0.0f};
      //   for (const auto& light : scene.lights.getLights()) {
      //     c += light->illuminate(ray, record);
      //   }
      //   return c;
      return record.surface->material.color;
    } else
      return m_bgColor;
  }

 private:
  Color m_bgColor;
};