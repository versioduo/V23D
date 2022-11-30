// © Kay Sievers <kay@versioduo.com>, 2022
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <cmath>

#include "Attitude.h"
#include "Euler.h"
#include "Quaternion.h"
#include "Vector3.h"

namespace V23D {
static inline float radToDeg(float rad) {
  return rad * 180.f / (float)M_PI;
}

static inline float degToRad(float deg) {
  return deg * (float)M_PI / 180.f;
}
};
