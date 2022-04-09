class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int pivot = 1;
        int leftIdx = 0, midIdx = 0, rightIdx = nums.size() - 1;
        
        while (midIdx <= rightIdx) {
            
            if (nums[midIdx] < pivot) {
                swap(nums[leftIdx], nums[midIdx]);
                midIdx++;
                leftIdx++;
            } else if (nums[midIdx] > pivot) {
                swap(nums[rightIdx], nums[midIdx]);
                rightIdx--;
            } else {
                midIdx++;
            }
        }
        return;
    }
};