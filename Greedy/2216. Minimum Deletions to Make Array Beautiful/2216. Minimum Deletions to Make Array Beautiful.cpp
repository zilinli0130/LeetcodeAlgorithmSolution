class Solution {
public:
    int minDeletion(vector<int>& nums) {
        
        int res = 0, n = nums.size();
        
        int i = 0;
        while (i < n) {
            
            int j = i + 1;
            while (j < n && nums[i] == nums[j]) {
                j++;
                res++;
            }
            
            if (j == n) {
                res++;
                break;
            } else {
                i = j + 1;
            }
        }
        return res;
    }
};