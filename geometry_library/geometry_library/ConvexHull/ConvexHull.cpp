//
//  ConvexHull.cpp
//  GeomLib
//
//  Created by uddipan mukherjee on 8/28/16.
//  Copyright © 2016 University of California, Irvine. All rights reserved.
//
#include <stack>

#include "ConvexHull.hpp"

namespace {

struct AngleCompare {
  Vec2 ref;
  AngleCompare(Vec2 ref) { this->ref = ref; }
  bool operator()(Vec2 A, Vec2 B) {
    double angle = (A - ref) ^ (B - ref);
    if (geom_lib::isConsideredSame(angle, 0.0)) {
      return LengthSquared(A - ref) < LengthSquared(B - ref);
    }
    return angle > 0.0;
  }
};

}  // namespace

namespace geom_lib {

// Gift wrapping
// Complexity: O(nh): n is the # points, h is # conv hull points.
std::vector<Vec2> ConvHullGiftWrap(const std::vector<Vec2> &allPoints) {
  std::vector<Vec2> CHull;
  if (allPoints.size() < 3) {
    return CHull;
  }

  // Identify lowest point
  unsigned LowestPoint = 0;
  for (unsigned u = 1; u < allPoints.size(); u++) {
    if (allPoints[u].y < allPoints[LowestPoint].y) {
      LowestPoint = u;
    }
  }

  unsigned prev = LowestPoint, curr;
  do {
    CHull.push_back(allPoints[prev]);
    curr = (prev + 1) % allPoints.size();
    for (unsigned u = 0; u < allPoints.size(); u++) {
      if (!isClockwise(allPoints[prev], allPoints[curr], allPoints[u])) {
        curr = u;
      }
    }
    prev = curr;
  } while (prev != LowestPoint);

  return CHull;
}

// Quick Hull
// Complexity: best case O(nLogn), worst O(n^2)
std::vector<Vec2> QuickHullRec(const Vec2 &A, const Vec2 &B,
                               std::vector<Vec2> &S) {
  std::vector<Vec2> PartialHull;
  if (S.empty()) return PartialHull;
  double distance = __DBL_MIN__;
  unsigned index = 0;
  for (unsigned u = 0; u < S.size(); u++) {
    double currDis = PointDistanceFromLine(A, B, S[u]);
    if (currDis < distance) {
      distance = currDis;
      index = u;
    }
  }
  std::vector<Vec2> S1, S2;
  for (unsigned u = 0; u < S.size(); u++) {
    if (u == index) continue;
    if (isClockwise(A, S[index], S[u])) {
      S1.push_back(S[u]);
    } else if (isClockwise(S[index], B, S[u])) {
      S2.push_back(S[u]);
    }
  }
  std::vector<Vec2> PartialHull1 = QuickHullRec(A, S[index], S1),
                    PartialHull2 = QuickHullRec(S[index], B, S2);
  PartialHull.insert(PartialHull.end(), PartialHull1.begin(),
                     PartialHull1.end());
  PartialHull.push_back(S[index]);
  PartialHull.insert(PartialHull.end(), PartialHull2.begin(),
                     PartialHull2.end());
  return PartialHull;
}

std::vector<Vec2> ConvHullQuickHull(const std::vector<Vec2> &allPoints) {
  // Find rightmost lowest and leftmost highest points
  unsigned RightLow = 0, LeftHigh = 0;
  for (unsigned u = 1; u < allPoints.size(); u++) {
    if ((allPoints[u].x < allPoints[LeftHigh].x) ||
        ((allPoints[u].x == allPoints[LeftHigh].x) &&
         (allPoints[u].y > allPoints[LeftHigh].y))) {
      LeftHigh = u;
    }
    if ((allPoints[u].x > allPoints[RightLow].x) ||
        ((allPoints[u].x == allPoints[RightLow].x) &&
         (allPoints[u].y < allPoints[RightLow].y))) {
      RightLow = u;
    }
  }
  std::vector<Vec2> S1, S2;
  for (unsigned u = 0; u < allPoints.size(); u++) {
    if (u == LeftHigh || u == RightLow) continue;
    if (isClockwise(allPoints[LeftHigh], allPoints[RightLow], allPoints[u])) {
      S1.push_back(allPoints[u]);
    } else {
      S2.push_back(allPoints[u]);
    }
  }
  std::vector<Vec2> CHull(1, allPoints[LeftHigh]);
  std::vector<Vec2> PartialHull1 = QuickHullRec(allPoints[LeftHigh],
                                                allPoints[RightLow], S1),
                    PartialHull2 = QuickHullRec(allPoints[RightLow],
                                                allPoints[LeftHigh], S2);
  CHull.insert(CHull.end(), PartialHull1.begin(), PartialHull1.end());
  CHull.push_back(allPoints[RightLow]);
  CHull.insert(CHull.end(), PartialHull2.begin(), PartialHull2.end());
  return CHull;
}

// Graham Scan
// Complexity:  O(nLogn)
std::vector<Vec2> ConvHullGrahamScan(const std::vector<Vec2> &allPoints) {
  // Find lowest rightmost point
  unsigned RightLow = 0;
  for (unsigned u = 1; u < allPoints.size(); u++) {
    if ((allPoints[u].y < allPoints[RightLow].y) ||
        ((allPoints[u].y == allPoints[RightLow].y) &&
         (allPoints[u].x > allPoints[RightLow].x))) {
      RightLow = u;
    }
  }

  // sort the points angularly about RightLow
  std::vector<Vec2> newPoints(allPoints);
  std::swap(newPoints[0], newPoints[RightLow]);

  sort(newPoints.begin(), newPoints.end(), AngleCompare(allPoints[RightLow]));

  std::stack<int> CurrentStack;
  CurrentStack.push(0);
  CurrentStack.push(1);

  unsigned idx = 2;
  while (idx < allPoints.size()) {
    int P1 = CurrentStack.top();
    CurrentStack.pop();
    int P2 = CurrentStack.top();
    if (isClockwise(newPoints[P2], newPoints[P1], newPoints[idx])) {
      CurrentStack.push(P1);
      CurrentStack.push(idx);
      idx++;
    }
  }
  std::vector<Vec2> ret;
  while (!CurrentStack.empty()) {
    ret.push_back(newPoints[CurrentStack.top()]);
    CurrentStack.pop();
  }
  return ret;
}

std::vector<Vec2> ConvHull(const std::vector<Vec2> &allPoints, int method) {
  if (allPoints.size() < 3) {
    return std::vector<Vec2>();
  }
  switch (method) {
    case GIFT_WRAP:
      return ConvHullGiftWrap(allPoints);
      break;
    case QUICK_HULL:
      return ConvHullQuickHull(allPoints);
      break;
    case GRAHAM_SCAN:
      return ConvHullGrahamScan(allPoints);
    default:
      return ConvHullGiftWrap(allPoints);
      break;
  }
}

}  // namespace geom_lib
