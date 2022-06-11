#include <memory>

#include "Object.h"
#include "Renderer/Window.h"
#include "math/Vector.h"
#include "surface/Surface.h"

int main() {
  Window window{640, 640};
  GroupSurface group;
  std::shared_ptr<Surface> s1;
  std::shared_ptr<Surface> s2;
  s1.reset(new Sphere{{-0.3f, 0.3f, 0.0f}, 0.3f, {0.8f, 0.2f, 0.3f}});
  s2.reset(new Sphere{{0.4f, 0.25f, 0.2f}, 0.3f, {0.3f, 0.2f, 0.8f}});
  group.add(s1);
  group.add(s2);
  int width = window.getwidth();
  int height = window.getHeight();
  float left = -1.0f;
  float right = 1.0f;
  float bottom = -1.0f;
  float top = 1.0f;
  while (window.isRunning()) {
    for (int i = 0; i < width; ++i) {
      for (int j = 0; j < height; ++j) {
        Ray ray = Ray::genOrthographicRay(left, right, bottom, top, width,
                                          height, i, j);
        HitRecord hitRecord = group.hit(ray, -1, 1);
        window.drawPixel(i, j, hitRecord.color);
      }
    }
  }
  return 0;
}