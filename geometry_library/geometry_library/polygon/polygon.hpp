//
//  polygon_area.hpp
//  geometry_library
//
//  Created by uddipan mukherjee on 4/22/17.
//  Copyright © 2017 uddipan mukherjee. All rights reserved.
//

#ifndef polygon_hpp
#define polygon_hpp

#include <stdio.h>
#include <vector>

#include "../include/Geomheader.h"

namespace geom_lib {

class Polygon {
 public:
  Polygon();
  Polygon(std::vector<Vec2> points);

  // Calculate area (negative if points are clockwise)
  double Area() const;

  // Checks if the specified point is inside the polygon
  bool IsInside(const Vec2 point) const;

  // Checks if the polygon is convex or reflex. The polygon is convex if all of
  // its angles are convex.Returns true for convex and false otherwise.
  bool IsConvex() const;

 private:
  // Points on the polygon in order
  std::vector<Vec2> points_;
};

}  // namespace geom_lib

#endif  // polygon_hpp
