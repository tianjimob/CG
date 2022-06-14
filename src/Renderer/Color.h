#pragma once

struct Color {
  float r;
  float g;
  float b;

  inline Color operator*(float scalar) const {
    return {r * scalar, g * scalar, b * scalar};
  }
  inline Color operator*(const Color &rhs) const {
    return {r * rhs.r, g * rhs.g, b * rhs.b};
  }
  inline Color operator+(const Color &rhs) const {
    Color result{r + rhs.r, g + rhs.g, b + rhs.b};
    return {result.r > 1.0f ? 1.0f : result.r,
            result.g > 1.0f ? 1.0f : result.g,
            result.b > 1.0f ? 1.0f : result.b};
  }
  inline Color operator+(float rhs) const {
    return *this + Color{rhs, rhs, rhs};
  }
  inline Color &operator+=(const Color &rhs) {
    Color result = *this + rhs;
    this->r = result.r;
    this->g = result.g;
    this->b = result.b;
    return *this;
  }

  inline Color operator/(float rhs) const {
    return {r / rhs, g / rhs, b / rhs};
  }
};

inline Color operator*(float scalar, const Color &color) {
  return color * scalar;
}