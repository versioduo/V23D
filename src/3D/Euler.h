// © Kay Sievers <kay@versioduo.com>, 2022
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "Quaternion.h"

namespace V23D {
class Euler {
public:
  float yaw{};
  float pitch{};
  float roll{};

  constexpr Euler(float y = 0, float p = 0, float r = 0) : yaw(y), pitch(p), roll(r) {}

  static constexpr Euler fromQuaternion(Quaternion q) {
    Euler e;
    const float ys = 2.f * (q.w * q.z + q.x * q.y);
    const float yc = 1.f - 2.f * (q.y * q.y + q.z * q.z);
    e.yaw          = atan2f(ys, yc);

    const float ps = 2.f * (q.w * q.y - q.z * q.x);
    e.pitch        = fabs(ps) >= 1.f ? copysignf((float)M_PI / 2.f, ps) : asinf(ps);

    const float rs = 2.f * (q.w * q.x + q.y * q.z);
    const float rc = 1.f - 2.f * (q.x * q.x + q.y * q.y);
    e.roll         = atan2f(rs, rc);

    return e;
  }
};
};
