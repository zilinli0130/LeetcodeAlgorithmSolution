# 1524. Number of Sub-arrays With Odd Sum

###### Tag: Dynamic Programming, Time Sequence

This problem uses two states `dp[i][1]` and `dp[i][0]` to represent the number of odd and even sum ending at a random index i. 

1.If the number associated with the current index is an odd number:

```
dp[i][0] = dp[i - 1][1];
dp[i][1] = dp[i - 1][0] + 1;
```


2.If the number associated with the current index is an even number:

```
dp[i][0] = dp[i - 1][0] + 1;
dp[i][1] = dp[i - 1][1];
```

