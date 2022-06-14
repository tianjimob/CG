#include <memory>

#include "Light.h"
#include "Material.h"
#include "Object.h"
#include "Renderer/Color.h"
#include "Renderer/Shader.h"
#include "Renderer/Window.h"
#include "Scene.h"
#include "math/Vector.h"
#include "surface/Surface.h"

int main() {
  Window window{1024, 768};

  Scene scene;

  std::shared_ptr<Surface> s1;
  std::shared_ptr<Surface> s2;
  std::shared_ptr<Surface> s3;
  Vec3 a{-0.3f, 0.0f, 0.0f};
  Vec3 b{0.4f, -0.05f, 0.1f};
  Vec3 c{-1.0f, -1.0f, 2.0f};
  Vec3 normal = (c - a).cross(b - a);
  Material m1{{0.3f, 0.3f, 0.3f}, {0.4f, 0.4f, 0.4f}, 1.1f};
  Material m2{{0.8f, 0.2f, 0.3f}, {0.4f, 0.4f, 0.4f}, 1.1f};
  Material m3{{0.3f, 0.2f, 0.8f}, {0.4f, 0.4f, 0.4f}, 1.1f};
  s1.reset(new Plane{normal, a, m1});
  s2.reset(new Sphere{{-0.3f, 0.3f, 0.0f}, 0.3f, m2});
  s3.reset(new Sphere{{0.4f, 0.25f, 0.1f}, 0.3f, m3});
  scene.surfaces.add(s1);
  scene.surfaces.add(s2);
  scene.surfaces.add(s3);

  std::shared_ptr<Light> l1;
  std::shared_ptr<Light> l2;
  l1.reset(new PointLight{{0.7f, 0.7f, 0.7f}, {0.0f, 1.0f, 0.8f}});
  l2.reset(new AmbientLight{{0.2f, 0.2f, 0.2f}});
  scene.lights.add(l1);
  scene.lights.add(l2);

  int width = window.getwidth();
  int height = window.getHeight();
  float left = -1.6f;
  float right = 1.6f;
  float bottom = -1.2f;
  float top = 1.2f;
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