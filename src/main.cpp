#include <memory>

#include "Light.h"
#include "Object.h"
#include "Renderer/Color.h"
#include "Renderer/Shader.h"
#include "Renderer/Window.h"
#include "Scene.h"
#include "math/Vector.h"
#include "surface/Surface.h"

int main() {
  Window window{640, 640};

  Scene scene;

  std::shared_ptr<Surface> s1;
  std::shared_ptr<Surface> s2;
  s1.reset(new Sphere{{-0.3f, 0.3f, 0.0f}, 0.3f, {0.8f, 0.2f, 0.3f}});
  s2.reset(new Sphere{{0.4f, 0.25f, 0.2f}, 0.3f, {0.3f, 0.2f, 0.8f}});
  scene.surfaces.add(s1);
  scene.surfaces.add(s2);

  std::shared_ptr<Light> l1;
  l1.reset(new PointLight{{1.0f, 1.0f, 1.0f}, {0.5f, 0.35f, 0.3f}});
  scene.lights.add(l1);

  int width = window.getwidth();
  int height = window.getHeight();
  float left = -1.0f;
  float right = 1.0f;
  float bottom = -1.0f;
  float top = 1.0f;
  Shader shader{{0.0f, 0.0f, 0.0f}};

  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < height; ++j) {
      Ray ray = Ray::genOrthographicRay(left, right, bottom, top, width, height,
                                        i, j);
      window.drawPixel(i, j, shader.shadeRay(ray, -1, 1, scene));
    }
  }
  while (window.isRunning())
    ;
  return 0;
}