//
//  Geomheader.h
//  GeomLib
//
//  Created by uddipan mukherjee on 4/9/12.
//  Copyright (c) 2012 University of California, Irvine. All rights reserved.
//

#ifndef GeomLib_Geomheader_h
#define GeomLib_Geomheader_h

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>


#include "Vec2.h"
#include "Vec3.h"
#include "Triangle.h"

using namespace std;

//Utility functions
//==============================================================================
//Distance of a line AB from a point P
inline double PointDistanceFromLine(const Vec2 &A, const Vec2 &B, const Vec2 &P)
{
    return ((B-A)^(B-P))/Length(B-A);
}

//Compare 2 floating point numbers/vectors
//==============================================================================
inline bool isConsideredSame(const double a, const double b)
{
    return abs(a-b) <= __DBL_EPSILON__;
}

inline bool isConsideredSame(const Vec2 a, const Vec2 b)
{
    return isConsideredSame(a.x, b.x) & isConsideredSame(a.y, b.y);
}

inline bool isConsideredSame(const Vec3 a, const Vec3 b)
{
    return isConsideredSame(a.x, b.x) & isConsideredSame(a.y, b.y)
         & isConsideredSame(a.z, b.z);
}
//==============================================================================

#endif
