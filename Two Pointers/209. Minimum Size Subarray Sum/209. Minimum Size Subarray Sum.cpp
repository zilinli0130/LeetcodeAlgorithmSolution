class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int j = -1;
        int sum = 0;
        int res = INT_MAX/2;
        //(j,i]
        for (int i = 0; i < nums.size(); i++) {
            
            sum += nums[i];
            while (sum >= target) {
                
                res = min(res, i - j);
                j++;
                sum -= nums[j];
            }
        }
        return res == INT_MAX/2? 0 : res;
    }
};