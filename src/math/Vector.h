#pragma once

#include <cmath>

struct Vec3 {
  float x;
  float y;
  float z;

  Vec3(float x, float y, float z) : x{x}, y{y}, z{z} {}

  inline Vec3 cross(const Vec3 &rhs) const {
    return {y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z,
            x * rhs.y - y * rhs.x};
  }

  inline Vec3 operator+(const Vec3 &rhs) const {
    return {x + rhs.x, y + rhs.y, z + rhs.z};
  }

  inline Vec3 operator-(const Vec3 &rhs) const {
    return {x - rhs.x, y - rhs.y, z - rhs.z};
  }

  inline Vec3 operator-() const { return {-x, -y, -z}; }

  inline Vec3 operator*(float scalar) const {
    return {x * scalar, y * scalar, z * scalar};
  }

  inline float operator*(const Vec3 &rhs) const {
    return x * rhs.x + y * rhs.y + z * rhs.z;
  }

  inline Vec3 operator/(float scalar) const {
    return {x / scalar, y / scalar, z / scalar};
  }
};

inline Vec3 operator*(float scalar, const Vec3 &vec3) { return vec3 * scalar; }

inline float vectorLength(const Vec3 &vector) {
  return std::sqrt(vector * vector);
}

struct Vec4 {
  float x;
  float y;
  float z;
  float w;

  Vec4() = default;
  Vec4(float x, float y, float z, float w = 1.0f) : x{x}, y{y}, z{z}, w{w} {}
};
