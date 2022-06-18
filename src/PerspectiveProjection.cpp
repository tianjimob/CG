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
  Mat4 persp = Mat4::perspective(0.1f, 100.0f);
  Mat4 vo = vp * ortho * persp;

  Vec3 eye{0.0f, 0.0f, 0.3f};
  Vec3 gaze{0.0f, 0.0f, -1.0f};
  Vec3 up{0.0f, 1.0f, 0.0f};
  Vec3 right = gaze.cross(up);
  Camera camera{eye, eye + gaze, up};

  Vec4 a{-0.5f, -0.5f, -1.0f};
  Vec4 b{0.5f, 0.5f, -0.1f};
  float speed = 15.f;
  Timestep ts;
  while (window.isRunning()) {
    if (window.isKeyPressed(Keycode::Up))
      eye = eye + gaze * speed * ts;
    if (window.isKeyPressed(Keycode::Down))
      eye = eye - gaze * speed * ts;
    if (window.isKeyPressed(Keycode::Right))
      eye = eye + right * speed * ts;
    if (window.isKeyPressed(Keycode::Left))
      eye = eye - right * speed * ts;
    if (window.isKeyPressed(Keycode::Space))
      eye = eye + up * speed * ts;
    if (window.isKeyPressed(Keycode::Shift))
      eye = eye - up * speed * ts;
    camera.setPosition(eye, eye + gaze);
    Mat4 voc = vo * camera;
    Vec4 p1 = voc * a;
    Vec4 p2 = voc * b;

    window.beginFrame();
    ts.onUpdate();
    window.drawLine((int)(p1.x / p1.w), (int)(p1.y / p1.w), (int)(p2.x / p2.w),
                    (int)(p2.y / p2.w));
    window.endFrame();
  }
}