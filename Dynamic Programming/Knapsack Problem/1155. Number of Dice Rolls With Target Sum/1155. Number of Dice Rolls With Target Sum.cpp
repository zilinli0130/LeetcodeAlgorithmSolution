class Solution {
public:
    int numRollsToTarget(int n, int limit, int target) {
        
        long res = 0;
        long MOD = 1e9 + 7;
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        for (int k = 1; k <= min(limit, target); k++) {
            dp[1][k] = 1;
        }
        
        for (int i = 2; i <= n; i++) {
            for (int k = 1; k <= target; k++) {
                for (int m = 1; m <= limit; m++) {
                    
                    if (k - m > 0 && k - m <= (i - 1) * limit && k - m != k) {
                        dp[i][k] = (dp[i][k] + dp[i - 1][k - m]) % MOD;
                        dp[i][k] %= MOD;
                    }
                }
            }
        }
        return dp[n][target];
    }
};