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

double Polygon::Area() {
  double Area = 0.0;
  for (unsigned u = 0; u < points_.size(); u++) {
    Area += points_[u].x * points_[(u + 1) % points_.size()].y -
            points_[u].y * points_[(u + 1) % points_.size()].x;
  }
  return Area / 2;
}

bool Polygon::IsInside(const Vec2 point) {
  int sgn = (points_[0] - point) * (points_[1] - points_[0]) > 0 ? 1 : -1;
  for (unsigned u = 0; u < points_.size(); u++) {
    Vec2 A = points_[u], B = points_[(u + 1) % points_.size()];
    if (((A - point) * (B - A)) * sgn < 0) return false;
  }
  return true;
}

}  // namespace geom_lib
