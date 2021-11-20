class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        if (nums.size() == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[nums.size() - 1] != nums[nums.size() - 2]) return nums[nums.size() - 1];
        
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            
            int mid = left + (right - left) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
            
            //[a,b,b]
            if (nums[mid] != nums[mid - 1] && nums[mid] == nums[mid + 1]) {
                if (mid % 2 == 0) {
                    left = mid + 2;
                } else {
                    right = mid - 1;
                }
            }
            
            //[b,b,a]
            if (nums[mid] == nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                if (mid % 2 == 0) {
                    right = mid - 2;
                } else {
                    left = mid + 1;
                }
            } 
        }
        return nums[left];
    }
};