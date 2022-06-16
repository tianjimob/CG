#pragma once

#include "Renderer/Color.h"

class Window {
public:
  Window(int width, int height);
  ~Window();
  void drawPixel(int x, int y, Color color) const;
  void drawLine(int x1, int y1, int x2, int y2) const;
  bool isRunning() const;
  inline int getwidth() const { return m_width; }
  inline int getHeight() const { return m_height; }

private:
  int m_width;
  int m_height;
};