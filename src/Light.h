#pragma once

#include <algorithm>
#include <memory>
#include <vector>

#include "Ray.h"
#include "Renderer/Color.h"
#include "math/Vector.h"
#include "surface/Surface.h"

class Light {
 public:
  virtual ~Light() = default;
  virtual Color illuminate(Ray ray, const HitRecord& record) = 0;
};

class PointLight : public Light {
 public:
  PointLight(const Color& color, const Vec3& position)
      : m_color(color), m_position(position) {}
  Color illuminate(Ray ray, const HitRecord& record) override {
    Vec3 x = ray.evaluate(record.t);
    float r = vectorLength(m_position - x);
    Vec3 l = (m_position - x) / r;
    Vec3 n = record.normal;
    Color E = std::max(0.0f, n * l) * m_color / (r * r);
    Vec3 v = -ray.direction / vectorLength(ray.direction);
    Color k = record.surface->getMaterial().evaluate(l, v, n);
    return k * E;
  }

 private:
  Color m_color;
  Vec3 m_position;
};

class AmbientLight : public Light {
 public:
  explicit AmbientLight(Color color) : m_color(color) {}
  Color illuminate(Ray ray, const HitRecord& record) override {
    Color k = record.surface->getMaterial().getReflectance();
    return k * m_color;
  }

 private:
  Color m_color;
};

class GroupLight {
 public:
  inline void add(std::shared_ptr<Light> light) { m_lights.push_back(light); }

  const auto& getLights() const { return m_lights; }

 private:
  std::vector<std::shared_ptr<Light>> m_lights;
};