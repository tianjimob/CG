#include "Renderer/Camera.h"
#include "Renderer/Timestep.h"
#include "Renderer/Window.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include <iostream>

int main() {
  int width = 1024;
  int height = 768;
  Window window{width, height};

  Mat4 vp = Mat4::viewport(0, 0, width, height);
  Mat4 ortho = Mat4::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
  Mat4 vo = vp * ortho;
  Vec3 position{0.5f, 0.5f, 0.0f};
  Camera camera{position};

  Vec4 a{-0.5f, -0.5f, 1.0f};
  Vec4 b{0.5f, 0.5f, 1.0f};
  float speed = 15.f;
  Timestep ts;
  while (window.isRunning()) {
    if (window.isKeyPressed(Keycode::Up))
      position = position + Vec3{0.0f, 0.0f, -speed * ts};
    else if (window.isKeyPressed(Keycode::Down))
      position = position + Vec3{0.0f, 0.0f, speed * ts};
    else if (window.isKeyPressed(Keycode::Right))
      position = position + Vec3{-speed * ts, 0.0f, 0.0f};
    else if (window.isKeyPressed(Keycode::Left))
      position = position + Vec3{speed * ts, 0.0f, 0.0f};
    else if (window.isKeyPressed(Keycode::Space))
      position = position + Vec3{0.0f, -speed * ts, 0.0f};
    else if (window.isKeyPressed(Keycode::Shift))
      position = position + Vec3{0.0f, speed * ts, 0.0f};
    camera.setPosition(position);
    Mat4 voc = vo * camera;
    Vec4 p1 = voc * a;
    Vec4 p2 = voc * b;

    window.beginFrame();
    ts.onUpdate();
    window.drawLine((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y);
    window.endFrame();
  }
}