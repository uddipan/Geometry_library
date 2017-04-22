//
//  main.cpp
//  GeomLib
//
//  Created by uddipan mukherjee on 4/9/12.
//  Copyright (c) 2012 University of California, Irvine. All rights reserved.
//
// Implementing geometry library
/*
 1. Area of a polygon implementation - AreaPoly.cpp
 */

#include "gtest/gtest.h"
#include "include/GeomHeader.h"

int Width = 600, Height = 500;
extern void display();

int main(int argc, char** argv) {
  // display routine required for testing
  /*glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(Width, Height);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Test Window");
  // glutDisplayFunc(display);
  glutMainLoop();*/

  // Testing framework
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
