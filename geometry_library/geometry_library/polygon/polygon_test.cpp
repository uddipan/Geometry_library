//
//  polygon_test.cpp
//  geometry_library
//
//  Created by uddipan mukherjee on 4/22/17.
//  Copyright © 2017 uddipan mukherjee. All rights reserved.
//

#include "polygon.hpp"

#include "gtest/gtest.h"

namespace {

Vec2 point_vec_point[] = {Vec2(1, 1)};
std::vector<Vec2> PointVector(point_vec_point,
                              point_vec_point +
                                  sizeof(point_vec_point) / sizeof(Vec2));
Vec2 point_vec_two_points[] = {Vec2(0, 0), Vec2(1, 1)};
std::vector<Vec2> TwoPointsVector(point_vec_two_points,
                                  point_vec_two_points +
                                      sizeof(point_vec_two_points) /
                                          sizeof(Vec2));

Vec2 point_vec_three_points[] = {Vec2(0, 0), Vec2(1, 1), Vec2(1, 0)};
std::vector<Vec2> ThreePointsVector(point_vec_three_points,
                                    point_vec_three_points +
                                        sizeof(point_vec_three_points) /
                                            sizeof(Vec2));

Vec2 point_vec_four_points[] = {Vec2(0, 0), Vec2(1, 0), Vec2(1, 1), Vec2(0, 1)};
std::vector<Vec2> FourPointsVector(point_vec_four_points,
                                   point_vec_four_points +
                                       sizeof(point_vec_four_points) /
                                           sizeof(Vec2));

geom_lib::Polygon Point(PointVector);
geom_lib::Polygon Line(TwoPointsVector);
geom_lib::Polygon Triangle(ThreePointsVector);
geom_lib::Polygon Quadrilateral(FourPointsVector);

}  // namespace

namespace geom_lib {

TEST(PolygonTest, AreaPointTest) {
  Polygon polygon;
  EXPECT_EQ(polygon.Area(), 0.0);
}

TEST(PolygonTest, AreaLineTest) { EXPECT_EQ(Line.Area(), 0.0); }

TEST(PolygonTest, AreaRightTriangleTest) { EXPECT_EQ(Triangle.Area(), -0.5); }

TEST(PolygonTest, AreaRightRectangleTest) {
  EXPECT_EQ(Quadrilateral.Area(), 1.0);
}

TEST(PolygonTest, PointInPolyGonTestOneEdge) {
  EXPECT_TRUE(Line.IsInside(Vec2(0, 0)));
  EXPECT_TRUE(Line.IsInside(Vec2(1, 1)));
  EXPECT_TRUE(Line.IsInside(Vec2(0.5, 0.5)));
  EXPECT_FALSE(Line.IsInside(Vec2(1, 2)));
  EXPECT_FALSE(Line.IsInside(Vec2(0, -1)));
}

TEST(PolygonTest, PointInPolyGonTestThreeEdges) {
  EXPECT_TRUE(Triangle.IsInside(Vec2(0, 0)));
  EXPECT_TRUE(Triangle.IsInside(Vec2(1, 1)));
  EXPECT_TRUE(Triangle.IsInside(Vec2(1, 0)));
  EXPECT_TRUE(Triangle.IsInside(Vec2(0.5, 0.5)));
  EXPECT_TRUE(Triangle.IsInside(Vec2(0.5, 0.2)));
  EXPECT_FALSE(Triangle.IsInside(Vec2(1, 2)));
  EXPECT_FALSE(Triangle.IsInside(Vec2(0, -1)));
}

TEST(PolygonTest, PointInPolyGonTestFourEdges) {
  EXPECT_TRUE(Quadrilateral.IsInside(Vec2(0, 0)));
  EXPECT_TRUE(Quadrilateral.IsInside(Vec2(1, 0)));
  EXPECT_TRUE(Quadrilateral.IsInside(Vec2(1, 1)));
  EXPECT_TRUE(Quadrilateral.IsInside(Vec2(0, 1)));
  EXPECT_TRUE(Quadrilateral.IsInside(Vec2(0.5, 0.5)));
  EXPECT_TRUE(Quadrilateral.IsInside(Vec2(0.5, 0.2)));
  EXPECT_FALSE(Quadrilateral.IsInside(Vec2(1, 2)));
  EXPECT_FALSE(Quadrilateral.IsInside(Vec2(0, -1)));

  // Randomly select points within the rectangle
  Vec2 random_point(double(rand() % 1001) / 1000.0,
                    double(rand() % 1001) / 1000.0);
  EXPECT_TRUE(Quadrilateral.IsInside(random_point));
  random_point =
      Vec2(double(rand() % 1001) / 1000.0, double(rand() % 1001) / 1000.0);
  EXPECT_TRUE(Quadrilateral.IsInside(random_point));
}

TEST(PolygonTest, ConvexTestOnePoint) { EXPECT_TRUE(Point.IsConvex()); }

TEST(PolygonTest, ConvexTestTwoPoints) { EXPECT_TRUE(Line.IsConvex()); }

TEST(PolygonTest, ConvexTestThreePoints) { EXPECT_TRUE(Triangle.IsConvex()); }

TEST(PolygonTest, ConvexTestFourPointsSimpleConvex) {
  EXPECT_TRUE(Quadrilateral.IsConvex());
}

TEST(PolygonTest, ConvexTestFourPointsSimpleReflex) {
  Vec2 point_vec[] = {Vec2(0, 0), Vec2(10, 0), Vec2(10, 10), Vec2(5, 2)};
  std::vector<Vec2> points(point_vec,
                           point_vec + sizeof(point_vec) / sizeof(Vec2));
  Polygon polygon(points);
  EXPECT_FALSE(polygon.IsConvex());
}

TEST(PolygonTest, ConvexTestFourPointsOverlap) {
  Vec2 point_vec[] = {Vec2(0, 0), Vec2(1, 0), Vec2(-5, 1), Vec2(0, 1)};
  std::vector<Vec2> points(point_vec,
                           point_vec + sizeof(point_vec) / sizeof(Vec2));
  Polygon polygon(points);
  EXPECT_FALSE(polygon.IsConvex());
}

}  // namespace geom_lib
