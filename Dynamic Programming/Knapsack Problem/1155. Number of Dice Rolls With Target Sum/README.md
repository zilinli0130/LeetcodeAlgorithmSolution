# 1155. Number of Dice Rolls With Target Sum

###### Tag: Dynamic Programming

###### Time: O(n * k * target)
###### Space: O(n * k * target)

This is a dynamic programming problem. We could define `dp[i][k]` as the ways to get total sum of `k` by given `i` number of dices.
The transition state function is listed below:
```
for (int m = 1; j <= number of dice face; m++) 
    if (k - m > 0 && k - m <= (i - 1) * number of dice face && k - m != k)
        dp[i][k] += dp[i - 1][k - m]
```

The last dp state is `dp[i - 1][k - m]` which is the total way to construct sum of `k - m` given one dice less than the current dp state.
The total sum `k-m` from last state needs to be valid: 
1. `k-m` is not overflow 
2. `i-1` number of dices are able to construct the `k-m` sum
3. The current sum `k` and the last sum `k-m` should not be identical, because if we can construct `k` sum by one less dice, there is no reason
   to roll one more dice to construct `k`, which is not possible.  



```

Note: There is not need to assign a variable to the number of dice face, because that is a inner property of the dice.
Naive way to construct 3 dimension dp: 
C++ Runtime: 670ms
Memory:39MB

class Solution {
public:
    int numRollsToTarget(int n, int limit, int target) {
        
        long res = 0;
        long MOD = 1e9 + 7;
                
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(limit + 1, vector<int>(target + 1, 0)));
        
        for (int j = 1; j <= limit; j++) {
            for (int m = 1; m <= min(j, target); m++) {
                dp[1][j][m] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j<= limit; j++) {
                for (int k = 1; k <= target; k++) {
                    for (int m = 1; m <= j; m++) {
                        
                        if (k - m > 0 && k - m <= (i - 1) * j && k - m != k) {
                            dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - m]) % MOD;
                            dp[i][j][k] %= MOD;
                        }
                    }
                }
            }
        }
        return dp[n][limit][target];
    }
};


```
