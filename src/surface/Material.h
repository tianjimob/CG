#pragma once

#include <algorithm>
#include <cmath>
#include <numbers>

#include "Renderer/Color.h"
#include "math/Vector.h"

class Material {
 public:
  Material(const Color& reflectance, const Color& ks, float p)
      : m_reflectance(reflectance), m_ks(ks), m_p(p) {}
  Color evaluate(Vec3 l, Vec3 v, Vec3 n) const {
    Color lambertian = m_reflectance / std::numbers::pi_v<float>;
    Vec3 h = (l + v) / vectorLength(l + v);
    Color mirror = m_ks * std::pow(std::max(0.0f, n * h), m_p);
    return lambertian + mirror;
  }
  Color getReflectance() const { return m_reflectance; }

 private:
  Color m_reflectance;
  Color m_ks;
  float m_p;
};