# 1621. Number of Sets of K Non-Overlapping Line Segments

###### Tag: Dynamic Programming, To Do Or Not To Do


This problem can use dynamic programming technique to keep track of the current states. We could define `dp0[i][k]` as the total ways to construct k line segments by using points
from 0 to i, and the ith point is not using to construct any line segments; `dp1[i][k]` as the total ways to construct k line segments by using points
from 0 to i, and the ith point is using to construct any line segments; The state transition shows as follow:


1. `dp1[i][k]`
  Since the ith point is used to construct a line segment, it means that the points before ith point must have constructed k-1 line segments:
  `dp1[i][k] = sum{dp0[j][k - 1] + dp1[j][k - 1]} for j = 0 to i - 1`


2. `dp0[i][k]`
  Since the ith point is not used to construct a line segment, it means that the points before ith point must be used to construct the kth line segments:
  `dp0[i][k] = sum{dp1[j][k]} for j = 0 to i - 1`
