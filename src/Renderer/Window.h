#pragma once

#include "Renderer/Color.h"
#include "easyx.h"

class Window {
 public:
  Window(int width, int height);
  ~Window() { closegraph(); }
  inline void drawPixel(int x, int y, Color color) const {
    putpixel(x, y,
             RGB((unsigned char)(color.r * 255), (unsigned char)(color.g * 255),
                 (unsigned char)(color.b * 255)));
  }
  bool isRunning() const;
  inline int getwidth() const { return m_width; }
  inline int getHeight() const { return m_height; }

 private:
  int m_width;
  int m_height;
};