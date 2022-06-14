#include "Object.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <memory>
#include <utility>

#include "Renderer/Color.h"
#include "math/Vector.h"
#include "surface/Surface.h"

HitRecord Sphere::hit(const Ray &r, float t0, float t1) {
  HitRecord record{std::make_shared<Sphere>(*this),
                   std::numeric_limits<float>::infinity(),
                   Vec3{0.0f, 0.0f, 0.0f}};
  Vec3 ec = r.origin - m_center;
  float dd = r.direction * r.direction;
  float discriminant = (r.direction * ec) * (r.direction * ec) -
                       dd * (ec * ec - m_radius * m_radius);
  if (discriminant < 0)
    return record;
  else if (discriminant == 0)
    record.t = -r.direction * ec / dd;
  else {  //(discriminant > 0)
    float r1 = -r.direction * ec + sqrtf(discriminant) / dd;
    float r2 = -r.direction * ec - sqrtf(discriminant) / dd;
    auto [tMin, tMax] = std::minmax(r1, r2);
    if (tMin > t0 && tMin < t1)
      record.t = tMin;
    else if (tMax > t0 && tMax < t1)
      record.t = tMax;
  }
  record.normal = r.evaluate(record.t) / m_radius;
  return record;
}

HitRecord Triangle::hit(const Ray &r, float t0, float t1) {
  // [c1 c2 r.direction] [B, Y, t]T = [c3]
  static const Vec3 c1{m_a - m_b};
  static const Vec3 c2{m_a - m_c};

  static const float &a = c1.x;
  static const float &b = c1.y;
  static const float &c = c1.z;
  static const float &d = c2.x;
  static const float &e = c2.y;
  static const float &f = c2.z;

  const float &g = r.direction.x;
  const float &h = r.direction.y;
  const float &i = r.direction.z;

  Vec3 c3{m_a - r.origin};
  const float &j = c3.x;
  const float &k = c3.y;
  const float &l = c3.z;

  HitRecord record{std::make_shared<Triangle>(*this),
                   std::numeric_limits<float>::infinity(),
                   Vec3{0.0f, 0.0f, 0.0f}};

  float M = a * (e * i - h * f) + b * (g * f - d * i) + c * (d * h - e * g);

  float t =
      f * (a * k - j * b) + e * (j * c - a * l) + d * (b * l - k * c) / -M;
  if (t < t0 || t > t1)
    return record;
  else if (float Y = i * (a * k - j * b) + h * (j * c - a * l) +
                     g * (b * l - k * c) / M;
           Y < 0 || Y > 1)
    return record;
  else if (float B = j * (e * i - h * f) + k * (g * f - d * i) +
                     l * (d * h - e * g) / M;
           B < 0 || B > 1 - Y)
    return record;
  record.t = t;
  Vec3 normal = (m_c - m_a).cross(m_b - m_a);
  record.normal = normal / vectorLength(normal);
  return record;
}

HitRecord Plane::hit(const Ray &r, float t0, float t1) {
  HitRecord record{std::make_shared<Plane>(*this),
                   std::numeric_limits<float>::infinity(),
                   Vec3{0.0f, 0.0f, 0.0f}};
  float denominator = m_normal.x * r.direction.x + m_normal.y * r.direction.y +
                      m_normal.z * r.direction.z;
  if (denominator == 0) return record;
  float numerator = m_normal.x * (m_point.x - r.origin.x) +
                    m_normal.y * (m_point.y - r.origin.y) +
                    m_normal.z * (m_point.z - r.origin.z);
  float t = numerator / denominator;
  if (t > t0 && t < t1) {
    record.t = t;
    record.normal = m_normal;
  }
  return record;
}
