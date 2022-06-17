#pragma once

#include <array>

#include "math/Matrix.h"
#include "math/Vector.h"

class Mat4 {
public:
  Mat4() = default;
  explicit Mat4(float diag) {
    m_mat4[0][0] = m_mat4[1][1] = m_mat4[2][2] = m_mat4[3][3] = diag;
  }
  Mat4(float a, float b, float c, float d) {
    m_mat4[0][0] = a;
    m_mat4[1][1] = b;
    m_mat4[2][2] = c;
    m_mat4[3][3] = d;
  }
  Mat4(float a, float b, float c) : Mat4(a, b, c, 1.0f) {}
  inline std::array<float, 4> &operator[](unsigned i) { return m_mat4[i]; }
  inline const std::array<float, 4> &operator[](unsigned i) const {
    return m_mat4[i];
  }

  Mat4 operator*(const Mat4 &rhs);
  Vec4 operator*(const Vec4 &rhs);

  static Mat4 ortho(float l, float r, float b, float t, float f, float n) {
    float rl = r - l;
    float tb = t - b;
    float fn = f - n;
    Mat4 mat;
    mat[0][0] = 2 / rl;
    mat[0][3] = -(r + l) / rl;
    mat[1][1] = 2 / tb;
    mat[1][3] = -(t + b) / tb;
    mat[2][2] = 2 / fn;
    mat[2][3] = -(f + n) / fn;
    mat[3][3] = 1;
    return mat;
  }

  static Mat4 viewport(int x, int y, int width, int height) {
    auto w = (float)width;
    auto h = (float)height;
    Mat4 mat(1.0f);
    mat[0][0] = w / 2;
    mat[0][3] = w / 2 + (float)x - 0.5f;
    mat[1][1] = h / 2;
    mat[1][3] = h / 2 + (float)y - 0.5f;
    return mat;
  }

private:
  std::array<std::array<float, 4>, 4> m_mat4{0};
};
