class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        if (nums.size() < 3) {
            return 0;
        }
        
        int res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int k = n - 1; k >= 2; k--) {
            
            int i = 0, j = k - 1;
            while (i < j) {
                
                if (nums[i] + nums[j] <= nums[k]) {
                    i++;
                } else {
                    res += j - i;
                    j--;
                }
            }
        }
        return res;
    }
};