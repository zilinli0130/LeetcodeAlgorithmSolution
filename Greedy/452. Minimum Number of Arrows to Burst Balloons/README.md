# 452. Minimum Number of Arrows to Burst Balloons
###### Tag: Greedy, Sorting

###### Time: O(Nlog(N))
###### Space: O(1) 

We could sort the intervals based on the non-decreasing order of their right end. If the left end of future intervals is less than or equal to the right end of current interval, they could be bursted together.