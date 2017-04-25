# Geometry_library
Simple C++ header only library for computational geometry problems.

Methods implemented:

1. POLYGON (include: polygon.hpp)
  -- Method : polygon.Area(), polygon.IsInside(Vec2 point)
     Computes area of a polygon with points in order

2.CONVEX HULL (include: ConvexHull.hpp)
  -- Methods: QuickHull, GrahamScan, Giftwrap

  -- Invocation: std::vector<Vec2> convex_hull = ConvHull(std::vector<Vec2> points)
     OR
     std::vector<Vec2> convex_hull = ConvHull(std::vector<Vec2> points, arg)
     arg = 0 (GiftWrap) ; arg = 1 (QuickHUll); arg = 2 (Graham scan)



Miscellaneous Notes:

gTest:
Please follow these steps to get gtest working with Xcode

1. Clone gTest from https://github.com/google/googletest
2. Navigate to gtest/googletest/googletest/xcode directory
   and open the Xcode project.
3. Make sure In Project Build Settings,
   Apple LLVM 8.0 - Language C++ settings are
   Dialect = C++14, C++ Standard Library = libstdc++
   These settings should match those in this XCode project.
4. Build the gTest project and link the gtest.Framework in this project.
   Typically the framewok will be created in 
   /Users/<username>/Library/Developer/Xcode/DerivedData/gtest-*** 
  (if you don’t know where that is, check Xcode->Preferences->Locations->Derived Data)

clang-format:
This project uses clang-format complying with Google style guide.
In order to enable that in Xcode, perform the following steps:

1. brew install clang-format
2. Launch Automator, click on ’Services’, then ’Choose’
3. Select ’Run Shell Script’ from the Library.In the shell script box, write this command:
    export PATH=/usr/local/bin:$PATH
    clang-format
4. Select ’Output replaces selected text’ and save under the name ’clang-format’
5. Create a .clang-format file in your home directory and write your options. For instance:

    BasedOnStyle: Google

5. select some code in Xcode, right-click and select clang-format:
