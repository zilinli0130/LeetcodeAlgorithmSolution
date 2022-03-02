class Solution {
    int preSum[21];
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 1) {
            return true;
        }
        nums.insert(nums.begin(), 0);
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }
        int gain = dfs(nums,1, n);
        return gain >= preSum[n] - gain;
    }
    
    int dfs(vector<int>& nums, int l, int r) {
        
        if (l == r) {
            return nums[l];
        }
        return max(preSum[r] - preSum[l - 1] - dfs(nums, l + 1, r), preSum[r] - preSum[l - 1] - dfs(nums, l, r - 1));
    }
};