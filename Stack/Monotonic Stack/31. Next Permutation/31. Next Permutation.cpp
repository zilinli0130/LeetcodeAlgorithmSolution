class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        
        //Find the 1st location which violates the non-decreasing order from back to font
        int idx1 = n - 2;
        while(idx1 >= 0 && nums[idx1] >= nums[idx1 + 1]) {
            idx1--;
        }
        if (idx1 < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        //Find the min element which is greater than nums[idx1]
        int idx2 = n - 1;
        while (idx2 > idx1 && nums[idx1] >= nums[idx2]) {
            idx2--;
        }        
        swap(nums[idx1], nums[idx2]);
        sort(nums.begin() + idx1 + 1, nums.end());
        return;

    }
};