class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            
            if (nums[i - 1] <= nums[i]) {
                continue;
            }
            
            if (i - 2 >= 0) {
                if (nums[i - 2] <= nums[i]) {
                    nums[i - 1] = nums[i];
                } else if (nums[i - 2] > nums[i]) {
                    nums[i] = nums[i -1];
                }
            }
            count++;
        }
        return count <= 1;
    }
};