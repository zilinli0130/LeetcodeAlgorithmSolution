class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        
        int n = obstacles.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][2] = 0;
        dp[0][1] = dp[0][3] = 1;
        
        for (int i = 1; i < n; i++) {
            
            int minVal = INT_MAX;
            int obs = obstacles[i];
            for (int j = 1; j <= 3; j++) {
                
                if (obs == j) {
                    dp[i][j] = INT_MAX;
                } else {
                    dp[i][j] = dp[i - 1][j];
                    minVal = min(minVal, dp[i][j]);
                }
            }
            
            for (int j = 1; j <= 3; j++) {
                if (dp[i][j] != minVal && j != obs) {
                    dp[i][j] = minVal + 1;
                }
            }
        }
        
        int res = INT_MAX;
        for (int j = 1; j <= 3; j++) {
            res = min(res, dp[n - 1][j]);
        }
        return res;
    }
};