#pragma once

#include "Material.h"
#include "math/Ray.h"
#include "math/Vector.h"
#include "surface/Surface.h"

class Sphere : public Surface {
public:
  Sphere(const Vec3 &center, float radius, const Material &material)
      : Surface(material), m_center(center), m_radius(radius){};
  HitRecord hit(const Ray &r, float t0, float t1) override;

private:
  Vec3 m_center;
  float m_radius;
};

class Triangle : public Surface {
public:
  Triangle(const Vec3 &a, const Vec3 &b, const Vec3 &c,
           const Material &material)
      : Surface(material), m_a(a), m_b(b), m_c(c) {}
  HitRecord hit(const Ray &r, float t0, float t1) override;

private:
  Vec3 m_a;
  Vec3 m_b;
  Vec3 m_c;
};

class Plane : public Surface {
public:
  Plane(const Vec3 &normal, const Vec3 &point, const Material &material)
      : Surface(material), m_normal(normal / vectorLength(normal)),
        m_point(point) {}
  HitRecord hit(const Ray &r, float t0, float t1) override;

private:
  Vec3 m_normal;
  Vec3 m_point;
};
