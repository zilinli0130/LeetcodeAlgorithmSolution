class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1, high = INT_MAX;
        while (low < high) {
            
            int mid = low + (high - low) / 2;
            if (isValid(nums, threshold, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    
    bool isValid(vector<int>& nums, int threshold, int divisor) {
        
        int res = 0;
        for (auto num : nums) {
            res += (num - 1) / divisor + 1; //Round up
        }
        return res <= threshold;
    }
};