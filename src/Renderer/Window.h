#pragma once

#include "Renderer/Color.h"
#include "Renderer/Timestep.h"

enum class Keycode : unsigned char {
  Shift = 0x10,
  Space = 0x20,
  Left = 0x25,
  Up = 0x26,
  Right = 0x27,
  Down = 0x28,
  Q = 0x51
};

class Window {
public:
  Window(int width, int height);
  ~Window();
  void beginFrame();
  void endFrame() const;
  void drawPixel(int x, int y, Color color) const;
  void drawLine(int x1, int y1, int x2, int y2) const;
  bool isKeyPressed(Keycode keycode) const;
  bool isKeyReleased(Keycode keycode) const;
  bool isRunning() const;
  inline int getwidth() const { return m_width; }
  inline int getHeight() const { return m_height; }

private:
  int m_width;
  int m_height;
};