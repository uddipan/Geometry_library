//
//  convex_hull_test.cpp
//  geometry_library
//
//  Created by uddipan mukherjee on 4/27/17.
//  Copyright © 2017 uddipan mukherjee. All rights reserved.
//

#include "ConvexHull.hpp"

#include "gtest/gtest.h"

#include "../polygon/polygon.hpp"

namespace {
  constexpr int kPointCntLow= 3;
  constexpr int kPointCntMedium= 120;
  constexpr int kPointCntHigh= 1000;
  constexpr int kPointCntDense= 10000;

  // Generate cnt random points and populate allPts vector with random points in [-1,1]
  void generate_random(std::vector<Vec2> &allPts, int cnt)
  {
    //generate random points each in [-1,1]
    srand(unsigned(time(NULL)));
    int pts_cnt = 3;//rand()%cnt;
    allPts = std::vector<Vec2>(pts_cnt,Vec2(0,0));
    
    for(unsigned u=0; u<pts_cnt; u++)
    {
      float a = -0.75 + double(rand()%4000)*1.5/4000.0;
      float b = -0.75 + double(rand()%7000)*1.5/7000.0;
      allPts[u] = Vec2(a,b);
    }
    
    allPts[0] = Vec2(0,0);
    allPts[1] = Vec2(0,1);
    allPts[2] = Vec2(1,1.5);
  }
  
  // Returns true if the convex hull of all_points is CHull.
  // Criteria for correctness:
  // 1. CHull points must belong to all_points. (TODO)
  // 2. CHull must be convex.
  // 3. All points in all_points must be inside CHull.
  bool IsHullCorrect(std::vector<Vec2>& all_points,std::vector<Vec2>& CHull){
    geom_lib::Polygon polygon(CHull);
    if(!polygon.IsConvex()){
      return false;
    }
    int idx = 0;
    for(const auto& point:all_points) {
      if(!polygon.IsInside(point)){
        return false;
      }
      idx++;
    }
    return true;
  }
} // namespace

namespace geom_lib {
  
  /*TEST(ConvexHullTest, GrahamScan) {
    std::vector<Vec2>allPts;
    generate_random(allPts, kPointCntLow);

    std::vector<Vec2> CHull = ConvHull(allPts, GRAHAM_SCAN);
    EXPECT_TRUE(IsHullCorrect(allPts, CHull));
    
  }*/
  
} // geom_lib
