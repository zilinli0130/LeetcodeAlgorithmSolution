class Solution {
    int subsetSum;
    vector<int> visited;
    int memo[20001][201];

public:
    bool canPartition(vector<int>& nums) {
        
        visited.resize(nums.size());
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;
        subsetSum = totalSum / 2;
        
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        return dfs(nums, 0, 0);
        
    }
    
    bool dfs(vector<int>& nums, int currentSum, int currentIdx) {
        
        if (memo[currentSum][currentIdx] != 0) {
            return false;
        }
        
        if (currentSum > subsetSum || currentIdx == nums.size()) {
            return false;
        }
        if (currentSum == subsetSum) {
            return true;
        }
        
        int lastNum = 0;
        for (int i = currentIdx; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (nums[i] == lastNum) continue;
            lastNum = nums[i];
            visited[i] = 1;
            if (dfs(nums, currentSum + nums[i], i + 1)) {
                return true;
            }
            visited[i] = 0;
        }
        memo[currentSum][currentIdx] = 1;
        return false;
    }
};