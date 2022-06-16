#include "Renderer/Window.h"
#include "math/Matrix.h"
#include "math/Vector.h"

int main() {
  int width = 1600;
  int height = 900;
  Window window{width, height};

  Mat4 vp = Mat4::viewport(width, height);
  Mat4 ortho = Mat4::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
  Mat4 vo = vp * ortho;

  Vec4 a{-0.5f, -0.5f, 1.0f};
  Vec4 b{0.5f, 0.5f, 1.0f};

  Vec4 p1 = vo * a;
  Vec4 p2 = vo * b;

  window.drawLine((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y);
  while (window.isRunning())
    ;
}
