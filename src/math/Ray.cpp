#include "Ray.h"

#include "math/Vector.h"

Ray Ray::genOrthographicRay(float left, float right, float bottom, float top,
                            int width, int height, int i, int j) {
  static Vec3 E{0.0f, 0.0f, 0.0f};
  static Vec3 U{1.0f, 0.0f, 0.0f};
  static Vec3 V{0.0f, 1.0f, 0.0f};
  static Vec3 W{0.0f, 0.0f, 1.0f};
  float u = left + (right - left) * ((float)i + 0.5f) / (float)width;
  float v = bottom + (top - bottom) * ((float)j + 0.5f) / (float)height;
  return {E + u * U + v * V, -W};
}

Ray Ray::genPerspectiveRay(float left, float right, float bottom, float top,
                           float distance, int width, int height, int i,
                           int j) {
  static Vec3 E{0.0f, 0.0f, distance};
  static Vec3 U{1.0f, 0.0f, 0.0f};
  static Vec3 V{0.0f, 1.0f, 0.0f};
  static Vec3 W{0.0f, 0.0f, 1.0f};
  float u = left + (right - left) * ((float)i + 0.5f) / (float)width;
  float v = bottom + (top - bottom) * ((float)j + 0.5f) / (float)height;
  return {E, -distance * W + u * U + v * V};
}