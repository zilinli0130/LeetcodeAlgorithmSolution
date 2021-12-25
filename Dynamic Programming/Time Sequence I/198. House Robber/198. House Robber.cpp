class Solution {
public:
    int rob(vector<int>& nums) {
        
        nums.insert(nums.begin(), 0);
        vector<vector<int>> dp(nums.size(), vector<int>(2,0));
        
        for (int i = 1; i < nums.size(); i++) {
            dp[i][1] = dp[i - 1][0] + nums[i];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};
