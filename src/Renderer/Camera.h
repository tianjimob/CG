#pragma once

#include "math/Matrix.h"
#include "math/Vector.h"
class Camera {
public:
  explicit Camera(const Vec3 &position) : m_position(position) {
    Vec3 g{0.0f, 0.0f, -1.0f};
    Vec3 t{0.0f, 1.0f, 0.0f};
    Vec3 w = -g;
    Vec3 u = t.cross(w);
    Vec3 v = w.cross(u);
    m_camera[0] = {u.x, u.y, u.z, -m_position.x};
    m_camera[1] = {v.x, v.y, v.z, -m_position.y};
    m_camera[2] = {w.x, w.y, w.z, -m_position.z};
    m_camera[3] = {0, 0, 0, 1};
  }
  explicit(false) inline operator const Mat4 &() const { return m_camera; }
  inline void setPosition(const Vec3 &position) {
    m_position = position;
    m_camera[0][3] = -m_position.x;
    m_camera[1][3] = -m_position.y;
    m_camera[2][3] = -m_position.z;
  }

private:
  Vec3 m_position;
  Mat4 m_camera;
};