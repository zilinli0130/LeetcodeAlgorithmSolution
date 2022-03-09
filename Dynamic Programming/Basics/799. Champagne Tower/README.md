# 799. Champagne Tower

###### Tag: Dynamic Programming, Simulation

We could assume that the `jth` glass on `ith` row can hold `dp[i][j]` amount of liquid. Since one glass can only physically hold one cup, the excess
amount of liquid `dp[i][j]` would fall into the cups of `jth` and `(j+1)th` on `(i+1)th` row equally volume of `(dp[i][j]-1)/2`.