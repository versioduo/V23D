// © Kay Sievers <kay@versioduo.com>, 2022
// SPDX-License-Identifier: Apache-2.0

#pragma once

namespace V23D {
class Vector3 {
public:
  float x;
  float y;
  float z;

  constexpr Vector3(float vx = 0, float vy = 0, float vz = 0) : x(vx), y(vy), z(vz) {}

  constexpr Vector3 normalize() {
    const float l = getLength();
    if (l > 0.0001f) {
      x *= 1.f / l;
      y *= 1.f / l;
      z *= 1.f / l;
    }

    return Vector3(x, y, z);
  }

  constexpr float getLength() const {
    return sqrtf(x * x + y * y + z * z);
  }

  constexpr Vector3 getCross(const Vector3 v) const {
    return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
  }

  constexpr float getDot(const Vector3 v) const {
    return x * v.x + y * v.y + z * v.z;
  }

  constexpr float getAngleBetween(const Vector3 v) const {
    return acosf(getDot(v));
  }
};
};
