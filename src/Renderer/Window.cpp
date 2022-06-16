#include "Window.h"

#include "easyx.h"

Window::Window(int width, int height) : m_width(width), m_height(height) {
  initgraph(m_width, m_height, EW_NOCLOSE);
  setorigin(0, m_height);
  setaspectratio(1, -1);
}

Window::~Window() { closegraph(); }

void Window::drawPixel(int x, int y, Color color) const {
  putpixel(x, y,
           RGB((unsigned char)(color.r * 255), (unsigned char)(color.g * 255),
               (unsigned char)(color.b * 255)));
}

void Window::drawLine(int x1, int y1, int x2, int y2) const {
  line(x1, y1, x2, y2);
}

bool Window::isRunning() const {
  ExMessage msg;
  while (peekmessage(&msg, EM_KEY)) {
    if (msg.message == WM_KEYUP && msg.vkcode == 0x51)
      return false;
  }
  return true;
}
