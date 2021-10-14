class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        
        int currentSum  = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<bool>> dp(totalSum + 1, vector<bool>(n + 1, 0));
        dp[0][0] = 1;
        
        
        for (auto x : nums) {
            
            currentSum += x;
            for (int sum = currentSum; sum >= x; sum--) {
                for (int num = n/2 + 1; num >= 1; num--) {
                    
                    if (dp[sum - x][num - 1] == 1) {
                        dp[sum][num] = 1;
                        if ((num != n) && (totalSum * num == sum * n)) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};