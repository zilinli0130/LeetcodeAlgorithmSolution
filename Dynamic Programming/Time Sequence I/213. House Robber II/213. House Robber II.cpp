class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        vector<int> nums1, nums2;
        for (int i = 0; i < nums.size() - 1; i++) nums1.push_back(nums[i]);
        for (int i = 1; i < nums.size(); i++) nums2.push_back(nums[i]);
        return max(helper(nums1), helper(nums2));
    }
    
    int helper(vector<int>& arr) {
        
        if (arr.size() == 0) return 0;
        if (arr.size() == 1) return arr[0];
        
        vector<vector<int>> dp(arr.size() + 1, vector<int>(2, 0));
        for (int i = 1; i <= arr.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + arr[i - 1];
        }
        return max(dp[arr.size()][0], dp[arr.size()][1]);
    }
};