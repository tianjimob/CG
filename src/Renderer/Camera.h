#pragma once

#include "math/Matrix.h"
#include "math/Vector.h"
class Camera {
public:
  explicit Camera(const Vec3 &eye, const Vec3 &center, const Vec3 &up)
      : m_eye(eye), m_center(center), m_up(up) {
    caculate();
    m_camera[3] = {0, 0, 0, 1};
  }
  explicit(false) inline operator const Mat4 &() const { return m_camera; }
  void setPosition(const Vec3 &eye, const Vec3 &center) {
    m_eye = eye;
    m_center = center;
    caculate();
  }

private:
  void caculate() {
    Vec3 g = (m_center - m_eye).normalize();
    Vec3 t = m_up.normalize();
    Vec3 w = -g;
    Vec3 u = t.cross(w);
    Vec3 v = w.cross(u);
    m_camera[0] = {u.x, u.y, u.z, -m_eye.x};
    m_camera[1] = {v.x, v.y, v.z, -m_eye.y};
    m_camera[2] = {w.x, w.y, w.z, -m_eye.z};
  }
  Vec3 m_eye;
  Vec3 m_center;
  Vec3 m_up;
  Mat4 m_camera;
};