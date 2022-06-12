#pragma once

#include "Light.h"
#include "surface/Surface.h"

struct Scene {
  GroupSurface surfaces;
  GroupLight lights;
};