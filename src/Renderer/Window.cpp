#include "Window.h"

#include <winuser.h>

#include "easyx.h"

Window::Window(int width, int height) : m_width(width), m_height(height) {
  initgraph(m_width, m_height);
  setorigin(0, m_height);
  setaspectratio(1, -1);
}

bool Window::isRunning() const {
  ExMessage msg;
  while (peekmessage(&msg, EM_KEY)) {
    if (msg.message == WM_KEYUP && msg.vkcode == 0x51) return false;
  }
  return true;
}
