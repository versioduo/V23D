// © Kay Sievers <kay@versioduo.com>, 2022
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "Quaternion.h"

namespace V23D {
class Attitude {
public:
  // SAAM – "A super fast attitude solution is obtained for consumer electronics
  // accelerometer-magnetometer combination. The quaternion parameterizing the
  // orientation is analytically derived from a least-square optimization that
  // maintains very simple form." – https://hal.inria.fr/hal-01922922
  static constexpr Quaternion fromAccelerometerMagnetometer(Vector3 a, Vector3 m) {
    const float mD = a.x * m.x + a.y * m.y + a.z * m.z;
    const float mN = sqrtf(1.f - mD * mD);

    V23D::Quaternion q;
    q.w = -a.y * (mN + m.x) + a.x * m.y;
    q.x = (a.z - 1.f) * (mN + m.x) + a.x * (mD - m.z);
    q.y = (a.z - 1.f) * m.y + a.y * (mD - m.z);
    q.z = a.z * mD - a.x * mN - m.z;
    return q.normalize();
  }
};
};
