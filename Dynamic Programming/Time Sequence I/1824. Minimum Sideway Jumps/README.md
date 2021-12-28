# 1824. Minimum Sideway Jumps

###### Tag: Dynamic Programming, Time Sequence

We can define `dp[i][j]` as the min sideway jumps at ith point with jth lane. If the jth lane has obstacle, `dp[i][j] = INT_MAX`. If not, the frog could either jump straightly from the i-1th point or make side jumps.