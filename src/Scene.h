#pragma once

#include "Renderer/Light.h"
#include "surface/Surface.h"
struct Scene {
  GroupSurface surfaces;
  GroupLight lights;
};