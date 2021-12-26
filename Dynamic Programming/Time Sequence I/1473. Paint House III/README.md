# 1473. Paint House III

###### Tag: Dynamic Programming, Time Sequence

We can define `dp[i][j][k]` as the min cost to paint i number of houses with target of j neighorhoods, where the ith house is painted with color k. Since the cost of current house only depends on the previous houses(the current house is either a neighbor with previous
house or not a neighbor with the previous house), we can come up with the state transisition as the following ways:

```
if houses[i] is already painted:
    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][kk]) -> ith house and i-1th house has different colors[k,kk]
    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]) -> ith house and i-1th house has the same color[k,k]

else :
    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][kk] + cost[i][k]) -> ith house and i-1th house has different colors[k, kk]
    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + cost[k]) -> ith house and i-1th house has the same color[k,k]

```

One optimization of this problem is to find out the min value of `dp[i - 1][j - 1][kk]` before looping through the choice of colors for
current house:

```
vector<pair<int, int>> temp
for (int kk = 1; kk <= n; kk++) {
    temp.push_back({dp[i - 1][j - 1][kk], kk});
}
sort(temp.begin(), temp.end());

//Consider that the last two houses are painted with the same color
dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + cost[k])

//Consider that the last two houses are painted with different colors
for (int k = 1; k <= n; k++) {
    if (k != temp[0].second) {
        dp[i][j][k] = min(dp[i][j][k], temp[0].first + cost[i][k]);
    } else {
        dp[i][j][k] = min(dp[i][j][k], temp[1].first + cost[i][k]);
    }
}

```