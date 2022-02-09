class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        if (nums.size() < 2) {
            return 0;
        }
        
        int res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int i = 0, j = 0;
        while (j < n) {
            
            if (abs(nums[i] - nums[j]) < k) {
                j++;
            } else if (abs(nums[i] - nums[j]) == k) {
                if (i != j) {
                    res++;
                    i++;
                    j++;
                    while (i < n && nums[i] == nums[i - 1]) i++;
                    while (j < n && nums[j] == nums[j - 1]) j++;
                } else {
                    j++;
                }
            } else {
                i++;
            }
        }
        return res;
    }
};

    