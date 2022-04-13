class Solution {
public:
    int integerBreak(int n) {
        
        vector<int> dp(n + 1, 0);
        dp[0] = 0, dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; i - j >= 0; j++) {
                dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
            }
        }
        return dp[n];
    }
};