class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int res = 0;
        int n = nums.size();
        int diff = INT_MAX/2;
        sort(nums.begin(), nums.end());
        
        
        for (int k = n - 1; k >= 2; k--) {
            
            int i = 0, j = k - 1;
            while (i < j) {
                
                if (nums[i] + nums[j] < target - nums[k]) {
                    if (abs(nums[i] + nums[j] + nums[k] - target) < diff) {
                        diff = abs(nums[i] + nums[j] + nums[k] - target);
                        res = nums[i] + nums[j] + nums[k];
                    }
                    i++;
                } else if (nums[i] + nums[j] > target - nums[k]) {
                    if (abs(nums[i] + nums[j] + nums[k] - target) < diff) {
                        diff = abs(nums[i] + nums[j] + nums[k] - target);
                        res = nums[i] + nums[j] + nums[k];
                    }
                    j--;
                                        
                } else {
                    return nums[i] + nums[j] + nums[k];
                }
            }
        }
        return res;
    }
};