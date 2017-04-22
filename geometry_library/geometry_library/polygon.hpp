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

#include "include/Geomheader.h"

class Polygon {
 public:
  Polygon();
  Polygon(std::vector<Vec2> points);

  // Calculate area
  double Area();

 private:
  // Points on the polygon in order
  std::vector<Vec2> points_;
};

#endif  // polygon_hpp
