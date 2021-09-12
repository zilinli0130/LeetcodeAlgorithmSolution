class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int low = 1, high = nums.size() - 1;
        while (low < high) {
            
            int k = low + (high - low) / 2;
            int count = 0;
            for (auto num : nums) {
                count += (num <= k);
            }
            if (count > k) {
                high = k;
            } else {
                low = k + 1;
            }
        }
        return low;
    }
};