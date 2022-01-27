# 375. Guess Number Higher or Lower II

###### Tag: Dynamic Programming, Basic

For any given range `[i,j]`, we could pick a pivot `k` in which `i<=k<=j`. The dp transition would be:
`dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]))`.
It tells us that we want to find out the min cost to guess the number between range `[i,j]`. Since we need to guarantee the cost is sufficient to be paid til the end of game, we need to pick the max cost between the left and right range w.r.t `k` pivot.
