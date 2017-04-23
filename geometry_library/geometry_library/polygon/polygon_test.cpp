//
//  polygon_test.cpp
//  geometry_library
//
//  Created by uddipan mukherjee on 4/22/17.
//  Copyright © 2017 uddipan mukherjee. All rights reserved.
//

#include "polygon.hpp"

#include "gtest/gtest.h"

TEST(PolygonTest, AreaPointTest) {
  Polygon polygon;
  EXPECT_EQ(polygon.Area(), 0.0);
}

TEST(PolygonTest, AreaLineTest) {
  Vec2 point_vec[] = {Vec2(0, 0), Vec2(1, 1)};
  std::vector<Vec2> points(point_vec,
                           point_vec + sizeof(point_vec) / sizeof(Vec2));
  Polygon polygon(points);
  EXPECT_EQ(polygon.Area(), 0.0);
}

TEST(PolygonTest, AreaRightTriangleTest) {
  Vec2 point_vec[] = {Vec2(0, 0), Vec2(1, 1), Vec2(1, 0)};
  std::vector<Vec2> points(point_vec,
                           point_vec + sizeof(point_vec) / sizeof(Vec2));
  Polygon polygon(points);
  EXPECT_EQ(polygon.Area(), -0.5);
}

TEST(PolygonTest, AreaRightRectangleTest) {
  Vec2 point_vec[] = {Vec2(0, 0), Vec2(1, 0), Vec2(1, 1), Vec2(0, 1)};
  std::vector<Vec2> points(point_vec,
                           point_vec + sizeof(point_vec) / sizeof(Vec2));
  Polygon polygon(points);
  EXPECT_EQ(polygon.Area(), 1.0);
}

TEST(PolygonTest, PointInPolyGonTestOneEdge) {
  Vec2 point_vec[] = {Vec2(0, 0), Vec2(1, 1)};
  std::vector<Vec2> points(point_vec,
                           point_vec + sizeof(point_vec) / sizeof(Vec2));
  Polygon polygon(points);
  EXPECT_TRUE(polygon.IsInside(Vec2(0, 0)));
  EXPECT_TRUE(polygon.IsInside(Vec2(1, 1)));
  EXPECT_TRUE(polygon.IsInside(Vec2(0.5, 0.5)));
  EXPECT_FALSE(polygon.IsInside(Vec2(1, 2)));
  EXPECT_FALSE(polygon.IsInside(Vec2(0, -1)));
}

TEST(PolygonTest, PointInPolyGonTestThreeEdges) {
  Vec2 point_vec[] = {Vec2(0, 0), Vec2(1, 1), Vec2(1, 0)};
  std::vector<Vec2> points(point_vec,
                           point_vec + sizeof(point_vec) / sizeof(Vec2));
  Polygon polygon(points);
  EXPECT_TRUE(polygon.IsInside(Vec2(0, 0)));
  EXPECT_TRUE(polygon.IsInside(Vec2(1, 1)));
  EXPECT_TRUE(polygon.IsInside(Vec2(1, 0)));
  EXPECT_TRUE(polygon.IsInside(Vec2(0.5, 0.5)));
  EXPECT_TRUE(polygon.IsInside(Vec2(0.5, 0.2)));
  EXPECT_FALSE(polygon.IsInside(Vec2(1, 2)));
  EXPECT_FALSE(polygon.IsInside(Vec2(0, -1)));
}

TEST(PolygonTest, PointInPolyGonTestFourEdges) {
  Vec2 point_vec[] = {Vec2(0, 0), Vec2(1, 0), Vec2(1, 1), Vec2(0, 1)};
  std::vector<Vec2> points(point_vec,
                           point_vec + sizeof(point_vec) / sizeof(Vec2));
  Polygon polygon(points);
  EXPECT_TRUE(polygon.IsInside(Vec2(0, 0)));
  EXPECT_TRUE(polygon.IsInside(Vec2(1, 0)));
  EXPECT_TRUE(polygon.IsInside(Vec2(1, 1)));
  EXPECT_TRUE(polygon.IsInside(Vec2(1, 0)));
  EXPECT_TRUE(polygon.IsInside(Vec2(0.5, 0.5)));
  EXPECT_TRUE(polygon.IsInside(Vec2(0.5, 0.2)));
  EXPECT_FALSE(polygon.IsInside(Vec2(1, 2)));
  EXPECT_FALSE(polygon.IsInside(Vec2(0, -1)));

  // Randomly select points within the rectangle
  Vec2 random_point(double(rand() % 1001) / 1000.0,
                    double(rand() % 1001) / 1000.0);
  EXPECT_TRUE(polygon.IsInside(random_point));
  random_point =
      Vec2(double(rand() % 1001) / 1000.0, double(rand() % 1001) / 1000.0);
  EXPECT_TRUE(polygon.IsInside(random_point));
}
