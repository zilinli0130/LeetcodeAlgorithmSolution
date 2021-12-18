# 221. Maximal Square

###### Tag: Dynamic Programming, Basic

We can define `dp[i][j]` as the max length of square that can be formed with `matrix[i][j]` as the right down side corner. It depends on the minimum values among `dp[i-1][j]`, `dp[i][j-1]`, `dp[i-1][j-1]`. 
