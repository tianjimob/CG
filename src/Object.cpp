#include "Object.h"

#include <algorithm>
#include <limits>
#include <memory>
#include <utility>

#include "Renderer/Color.h"
#include "math/Vector.h"
#include "surface/Surface.h"

Sphere::Sphere(const Vec3& center, float radius, const Color& color)
    : m_center(center), m_radius(radius), m_color(color) {}

HitRecord Sphere::hit(Ray r, float t0, float t1) {
  HitRecord record{std::make_shared<Sphere>(*this),
                   std::numeric_limits<float>::infinity(), m_color,
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
    std::pair<float, float> tMinMax = std::minmax(r1, r2);
    if (tMinMax.first > t0 && tMinMax.second < t1)
      record.t = tMinMax.first;
    else if (tMinMax.second > t0 && tMinMax.second < t1)
      record.t = tMinMax.second;
  }
  record.normal = r.evaluate(record.t) / m_radius;
  return record;
}
