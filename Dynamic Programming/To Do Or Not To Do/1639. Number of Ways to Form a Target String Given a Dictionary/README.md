# 1639. Number of Ways to Form a Target String Given a Dictionary

###### Tag: Dynamic Programming, To Do Or Not To Do

We can use dynamic programming to solve this problem by defining `dp[i][k]` as the number of ways to construct `target[0:i]` by using `words[0:k]`.
The strategy is that we can either use `words[k]` to construct `target[0:i]` or not use `words[k]` to construct `target[0:i]`:


1. Do not use `words[k]` to construct `target[0:i]`:
    `dp[i][k] = dp[i][k - 1]`
2. Use `words[k]` to construct `target[0:i]` if `target[i] == words[k]`:
    `dp[i][k] += dp[i - 1][k - 1] * count(target[i] == words[k])`
