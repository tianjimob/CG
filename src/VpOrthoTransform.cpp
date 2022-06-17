#include "Renderer/Window.h"
#include "math/Matrix.h"
#include "math/Vector.h"

int main() {
  int width = 1600;
  int height = 900;
  Window window{width, height};

  Mat4 vpLeftBottom = Mat4::viewport(0, 0, width / 2, height / 2);
  Mat4 vpRightBottom = Mat4::viewport(800, 0, width / 2, height / 2);
  Mat4 vpLeftTop = Mat4::viewport(0, 450, width / 2, height / 2);
  Mat4 vpRightTop = Mat4::viewport(800, 450, width / 2, height / 2);

  Mat4 ortho = Mat4::ortho(-1.6f, 1.6f, -0.9f, 0.9f, -1.0f, 1.0f);

  Mat4 voLeftBottom = vpLeftBottom * ortho;
  Mat4 voRightBottom = vpRightBottom * ortho;
  Mat4 voLeftTop = vpLeftTop * ortho;
  Mat4 voRightTop = vpRightTop * ortho;

  Vec4 a{-0.8f, -0.45f, 1.0f};
  Vec4 b{0.8f, 0.45f, 1.0f};

  Vec4 o1 = voLeftBottom * a;
  Vec4 o2 = voLeftBottom * b;
  Vec4 p1 = voRightBottom * a;
  Vec4 p2 = voRightBottom * b;
  Vec4 q1 = voLeftTop * a;
  Vec4 q2 = voLeftTop * b;
  Vec4 r1 = voRightTop * a;
  Vec4 r2 = voRightTop * b;

  window.drawLine((int)o1.x, (int)o1.y, (int)o2.x, (int)o2.y);
  window.drawLine((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y);
  window.drawLine((int)q1.x, (int)q1.y, (int)q2.x, (int)q2.y);
  window.drawLine((int)r1.x, (int)r1.y, (int)r2.x, (int)r2.y);
  while (window.isRunning())
    ;
}
