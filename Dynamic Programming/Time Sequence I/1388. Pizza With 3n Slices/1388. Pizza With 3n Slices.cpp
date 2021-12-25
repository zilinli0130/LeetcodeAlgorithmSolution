class Solution {
    int k;
public:
    int maxSizeSlices(vector<int>& slices) {
        
        k = slices.size() / 3;
        vector<int> slices1, slices2;
        for (int i = 0; i < slices.size() - 1; i++) slices1.push_back(slices[i]);
        for (int i = 1; i < slices.size(); i++) slices2.push_back(slices[i]);
        return max(helper(slices1), helper(slices2));
    }
    
    int helper(vector<int>& nums) {
        
        vector<vector<int>> dp0(nums.size() + 1, vector<int>(k + 1, 0));
        vector<vector<int>> dp1(nums.size() + 1, vector<int>(k + 1, 0));
        
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= min(k, i); j++) {
                dp0[i][j] = max(dp0[i - 1][j], dp1[i - 1][j]);
                dp1[i][j] = dp0[i - 1][j - 1] + nums[i - 1];
            }
        }
        return max(dp0[nums.size()][k], dp1[nums.size()][k]);
    }
};