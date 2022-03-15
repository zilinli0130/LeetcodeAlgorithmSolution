using LL = long long;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) 
    {
        LL res = INT_MIN;
        int m = points.size(), n = points[0].size();
        if (m == 1)
        {
            return *max_element(points[0].begin(), points[0].end());
        }
        
        vector<vector<LL>> dp(m, vector<LL>(n, INT_MIN));
        
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = points[0][j];
        }
        
        for (int i = 1; i < m; i++)            
        {
            LL curMax = INT_MIN;            
            for (int j = 0; j < n; j++)
            {
                curMax = max(curMax, dp[i - 1][j] + j);
                dp[i][j] = max(dp[i][j], curMax + points[i][j] - j);
                res = max(res, dp[i][j]);
            }
            
            curMax = INT_MIN;            
            for (int j=n - 1; j >= 0; j--)
            {
                curMax = max(curMax, dp[i - 1][j] - j);
                dp[i][j] = max(dp[i][j], curMax + points[i][j] + j);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};