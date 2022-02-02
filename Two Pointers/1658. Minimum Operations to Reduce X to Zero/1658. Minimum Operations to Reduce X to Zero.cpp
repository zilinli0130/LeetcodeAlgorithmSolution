class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int j = -1; //(j,i]
        int len = 0;
        int curSum = 0;
        int n = nums.size();    
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < x) {
            return -1;
        }
        if (sum == x) {
            return n;
        }
        for (int i = 0; i < n; i++) {
            
            curSum += nums[i];
            while (curSum > sum - x) {
                j++;
                curSum -= nums[j];
            }
            if (curSum == sum - x) {
                len = max(len, i - j);
            }
        }
        return len == 0? -1 : n - len;
    }
};

