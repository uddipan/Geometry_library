//
//  polygon_test.cpp
//  geometry_library
//
//  Created by uddipan mukherjee on 4/22/17.
//  Copyright © 2017 uddipan mukherjee. All rights reserved.
//

#include "polygon.hpp"

#include "gtest/gtest.h"

TEST(PolygonTest, AreaTest) {
    Polygon polygon;
    EXPECT_EQ(polygon.Area(), 0.0);
}
