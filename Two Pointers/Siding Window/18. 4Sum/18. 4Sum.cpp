class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        if (nums.size() < 4) {
            return {};
        }
        
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (int m = n - 1; m >= 0; m--) {
            
            if (m < n - 1 && nums[m] == nums[m + 1]) continue;
            for (int k = m - 1; k >= 0; k--) {
                
                if (k < m - 1 && nums[k] == nums[k + 1]) continue;
                int i = 0, j = k - 1;
                while (i < j) {
                    
                    if (nums[i] + nums[j] < target - nums[k]- nums[m]) {
                        i++;
                    } else if (nums[i] + nums[j] > target - nums[k] - nums[m]) {
                        j--;
                    } else {
                        res.push_back({nums[i],nums[j],nums[k],nums[m]});
                        i++;
                        j--;
                        while (i < j && nums[i] == nums[i - 1]) i++;
                        while (i < j && nums[j] == nums[j + 1]) j--; 
                    }
                }
            }
        }
        return res;
    }
};
