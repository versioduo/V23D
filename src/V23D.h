// © Kay Sievers <kay@versioduo.com>, 2022
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <cmath>

#include "3D/Attitude.h"
#include "3D/Euler.h"
#include "3D/Quaternion.h"
#include "3D/Vector3.h"

namespace V23D {
static inline float radToDeg(float rad) {
  return rad * 180.f / (float)M_PI;
}

static inline float degToRad(float deg) {
  return deg * (float)M_PI / 180.f;
}
};
