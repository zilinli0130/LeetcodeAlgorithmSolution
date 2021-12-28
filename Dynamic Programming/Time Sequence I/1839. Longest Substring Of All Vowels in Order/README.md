# 1839. Longest Substring Of All Vowels in Order

###### Tag: Dynamic Programming, Time Sequence

We can define `dp[i][j]` as the longest beautiful substring ending with `j` letter at the `i`th round. The state transistion is shown below:

```
if current string is ending with j:
dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + 1

else:
dp[i][j] = INT_MIN;
```