//
//  polygon_area.cpp
//  geometry_library
//
//  Created by uddipan mukherjee on 4/22/17.
//  Copyright © 2017 uddipan mukherjee. All rights reserved.
//

#include "polygon.hpp"

namespace geom_lib {

Polygon::Polygon() : points_(std::vector<Vec2>()) {}

Polygon::Polygon(std::vector<Vec2> points) : points_(points) {}

double Polygon::Area() const {
  double Area = 0.0;
  for (unsigned u = 0; u < points_.size(); u++) {
    Area += points_[u].x * points_[(u + 1) % points_.size()].y -
            points_[u].y * points_[(u + 1) % points_.size()].x;
  }
  return Area / 2;
}

bool Polygon::IsInside(const Vec2 point) const {
  int sgn = (points_[0] - point) * (points_[1] - points_[0]) > 0 ? 1 : -1;
  for (unsigned u = 0; u < points_.size(); u++) {
    Vec2 A = points_[u], B = points_[(u + 1) % points_.size()];
    if (((A - point) * (B - A)) * sgn < 0) return false;
  }
  return true;
}

bool Polygon::IsConvex() const {
  int sgn = 0;
  size_t sz = points_.size();
  for (size_t u = 0; u < sz; u++) {
    size_t prev = (u + sz - 1) % sz;
    size_t next = (u + 1) % sz;
    Vec2 A(points_[u] - points_[prev]);
    Vec2 B(points_[next] - points_[u]);
    double direction = A ^ B;
    if (sgn == 0) {
      sgn = direction >= 0 ? 1 : -1;
    }
    if (sgn * direction < 0) {
      return false;
    }
  }
  return true;
}

}  // namespace geom_lib
