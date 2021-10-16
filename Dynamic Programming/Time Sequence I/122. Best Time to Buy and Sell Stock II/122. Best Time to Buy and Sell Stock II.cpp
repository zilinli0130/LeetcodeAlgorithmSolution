class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        prices.insert(prices.begin(), -1);
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -INT_MAX;
        
        for (int i = 1; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n][0];
    }
};

/*
dp[i][0] -> max profit so far at ith round without any stock in hand 
dp[i][1] -> max profit so far at ith round with stock in hand

                                            
dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);

*/