//
//  ConvexHull.hpp
//  GeomLib
//
//  Created by uddipan mukherjee on 8/28/16.
//  Copyright © 2016 University of California, Irvine. All rights reserved.
//

#ifndef ConvexHull_hpp
#define ConvexHull_hpp

#include "../include/Geomheader.h"

namespace geom_lib {

enum { GIFT_WRAP, QUICK_HULL, GRAHAM_SCAN };

inline bool isClockwise(const Vec2 &A, const Vec2 &B, const Vec2 &C) {
  return ((B - A) ^ (C - B)) >= 0;
}

// Method:Gift wrapping
std::vector<Vec2> ConvHullGiftWrap(const std::vector<Vec2> &allPoints);

// Method: QuickHull
std::vector<Vec2> ConvHullQuickHull(const std::vector<Vec2> &allPoints);

// Method: Graham's Scan
std::vector<Vec2> ConvHullGrahamScan(const std::vector<Vec2> &allPoints);

// Main invocation of Convex Hull with method passed as parameter
std::vector<Vec2> ConvHull(const std::vector<Vec2> &allPoints,
                           int method = GIFT_WRAP);

}  // namespace geom_lib

#endif /* ConvexHull_hpp */
