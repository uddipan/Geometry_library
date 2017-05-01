//
//  GeomHeaderTest.cpp
//  geometry_library
//
//  Created by uddipan mukherjee on 4/30/17.
//  Copyright © 2017 uddipan mukherjee. All rights reserved.
//

#include "polygon.hpp"

#include "gtest/gtest.h"

namespace geom_lib {

TEST(GeomHeaderTest, ProjectionOnVectorTest) {
  Vec2 A(0, 0), B(11, 11);
  Vec2 P(3, 4), Q(-7, 1), R(20, 10);
  EXPECT_TRUE(isConsideredSame(ProjectionOnVector(A, B, P),
                               Length(Vec2(3.5, 3.5)) / Length(B - A)));
  EXPECT_TRUE(isConsideredSame(ProjectionOnVector(A, B, Q),
                               -Length(Vec2(-3, -3)) / Length(B - A)));
  EXPECT_TRUE(isConsideredSame(ProjectionOnVector(A, B, R),
                               1 + Length(Vec2(4, 4)) / Length(B - A)));
}

TEST(GeomHeaderTest, PointDistanceFromVectorTest) {
  Vec2 A(0, 0), B(1, 1);
  Vec2 P0(0.1, 0.1), P1(2, 2), P2(-3.5, -3.5);
  EXPECT_TRUE(isConsideredSame(PointDistanceFromVector(A, B, A), 0));
  EXPECT_TRUE(isConsideredSame(PointDistanceFromVector(A, B, B), 0));
  EXPECT_TRUE(isConsideredSame(PointDistanceFromVector(A, B, P0), 0));
  EXPECT_TRUE(isConsideredSame(PointDistanceFromVector(A, B, P1), 0));
  EXPECT_TRUE(isConsideredSame(PointDistanceFromVector(A, B, P2), 0));
  Vec2 Q0(3, -1), Q1(3, 4), Q2(-5, -11);
  EXPECT_TRUE(isConsideredSame(PointDistanceFromVector(A, B, Q0), sqrt(8)));
  EXPECT_TRUE(isConsideredSame(PointDistanceFromVector(A, B, Q1), sqrt(0.5)));
  EXPECT_TRUE(isConsideredSame(PointDistanceFromVector(A, B, Q2), sqrt(18)));
}

TEST(GeomHeaderTest, PointDistanceFromLineTest) {
  Vec2 A(0, 0), B(4, 4);
  Vec2 P(0.23, 0.23), Q(-10, -1), R(10, 1), S(3, 4);
  EXPECT_TRUE(isConsideredSame(PointDistanceFromLine(A, B, P), 0));
  EXPECT_TRUE(isConsideredSame(PointDistanceFromLine(A, B, Q), Length(A - Q)));
  EXPECT_TRUE(isConsideredSame(PointDistanceFromLine(A, B, R), Length(B - R)));
  EXPECT_TRUE(isConsideredSame(PointDistanceFromLine(A, B, S),
                               Length(S - Vec2(3.5, 3.5))));
}

}  // namespace geom_lib
