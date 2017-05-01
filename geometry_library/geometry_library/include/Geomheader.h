//
//  Geomheader.h
//  GeomLib
//
//  Created by uddipan mukherjee on 4/9/12.
//  Copyright (c) 2012 University of California, Irvine. All rights reserved.
//

#ifndef GeomLib_Geomheader_h
#define GeomLib_Geomheader_h

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>

#include "Vec2.h"
#include "Vec3.h"

// error bound
#define EPSILON 1e-6

namespace geom_lib {

// Returns the projection of point P on vector AB. If the projection is on the
// segment AB, it is in [0,1].
inline double ProjectionOnVector(const Vec2 &A, const Vec2 &B, const Vec2 &P) {
  return (((B - A) * (P - A)) / LengthSquared(B - A));
}

// Returns the distance of a vector AB from a point P
inline double PointDistanceFromVector(const Vec2 &A, const Vec2 &B,
                                      const Vec2 &P) {
  double ratio = ProjectionOnVector(A, B, P);
  Vec2 projection = A + ratio * (B - A);
  return Length(P - projection);
}

// Returns the distance of a line AB from a point P
inline double PointDistanceFromLine(const Vec2 &A, const Vec2 &B,
                                    const Vec2 &P) {
  double ratio = ProjectionOnVector(A, B, P);
  if (ratio <= 0) {
    return Length(P - A);
  }
  if (ratio >= 1) {
    return Length(P - B);
  }
  return PointDistanceFromVector(A, B, P);
}

// Compare 2 floating point numbers. Returns true if the numbers are equal with
// a tolerance, false otherwise.
inline bool isConsideredSame(const double a, const double b) {
  return std::abs(a - b) <= EPSILON;
}

}  // namespace geom_lib

#endif
