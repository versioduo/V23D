// © Kay Sievers <kay@versioduo.com>, 2022
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "Vector3.h"

namespace V23D {
class Quaternion {
public:
  float w, x, y, z;

  constexpr Quaternion(float qw = 1, float qx = 0, float qy = 0, float qz = 0) : w(qw), x(qx), y(qy), z(qz) {}

  constexpr Quaternion operator*(const Quaternion &q) const {
    return Quaternion(w * q.w - x * q.x - y * q.y - z * q.z,
                      w * q.x + x * q.w + y * q.z - z * q.y,
                      w * q.y - x * q.z + y * q.w + z * q.x,
                      w * q.z + x * q.y - y * q.x + z * q.w);
  }

  static constexpr Quaternion fromAxisAngle(Vector3 axis, float angle) {
    const float c = sinf(angle / 2.f);
    return Quaternion(cosf(angle / 2.f), c * axis.x, c * axis.y, c * axis.z);
  }

  constexpr float getAxisAngle(Vector3 &axis) const {
    const float angle   = 2.f * acos(w);
    const float divider = sqrtf(1.f - w * w);

    if (divider > 0.0001f) {
      axis.x = x / divider;
      axis.y = y / divider;
      axis.z = z / divider;

    } else {
      axis.x = 1;
      axis.y = 0;
      axis.z = 0;
    }

    return angle;
  }

  constexpr Quaternion normalize() {
    const float l = getLength();
    if (l > 0.0001f) {
      w *= 1.f / l;
      x *= 1.f / l;
      y *= 1.f / l;
      z *= 1.f / l;
    }

    return Quaternion(w, x, y, z);
  }

  constexpr float getLength() const {
    return sqrtf(w * w + x * x + y * y + z * z);
  }

  constexpr Quaternion getConjugate() const {
    return Quaternion(w, -x, -y, -z);
  }

  constexpr bool isEqual(const Quaternion q) const {
    if (fabs(w - q.w) > 0.0001f)
      return false;

    if (fabs(x - q.x) > 0.0001f)
      return false;

    if (fabs(y - q.y) > 0.0001f)
      return false;

    if (fabs(z - q.z) > 0.0001f)
      return false;

    return true;
  }
};
};
