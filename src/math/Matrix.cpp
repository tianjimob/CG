#include "Matrix.h"
#include "math/Vector.h"

Mat4 operator*(const Mat4 &rhs);

Mat4 Mat4::operator*(const Mat4 &rhs) {
  Mat4 mat;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      float sum = 0;
      for (int k = 0; k < 4; ++k) {
        sum += m_mat4[i][k] * rhs[k][j];
      }
      mat[i][j] = sum;
    }
  }
  return mat;
}

Vec4 Mat4::operator*(const Vec4 &rhs) {
  Vec4 vec4;
  vec4.x = m_mat4[0][0] * rhs.x + m_mat4[0][1] * rhs.y + m_mat4[0][2] * rhs.z +
           m_mat4[0][3] * rhs.w;
  vec4.y = m_mat4[1][0] * rhs.x + m_mat4[1][1] * rhs.y + m_mat4[1][2] * rhs.z +
           m_mat4[1][3] * rhs.w;
  vec4.z = m_mat4[2][0] * rhs.x + m_mat4[2][1] * rhs.y + m_mat4[2][2] * rhs.z +
           m_mat4[2][3] * rhs.w;
  vec4.w = m_mat4[3][0] * rhs.x + m_mat4[3][1] * rhs.y + m_mat4[3][2] * rhs.z +
           m_mat4[3][3] * rhs.w;
  return vec4;
}