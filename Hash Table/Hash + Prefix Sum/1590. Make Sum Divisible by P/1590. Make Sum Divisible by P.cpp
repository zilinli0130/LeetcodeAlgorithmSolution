typedef long long LL;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        LL res = INT_MAX, totalSum = 0;
        unordered_map<LL, LL> Map;
        Map[0] = -1;
        
        for (const auto& num : nums) {
            totalSum  = (totalSum + num) % p;
        }
        LL totalSumRemainder = totalSum % p;
        
        if (totalSumRemainder == 0) {
            return 0;
        }
        
        LL prefixSum = 0;
        for (int j = 0; j < nums.size(); j++) {
            
            prefixSum  = (prefixSum + nums[j]) % p;
            LL curPrefixSumRemainder = prefixSum % p;
            
            LL r = (curPrefixSumRemainder - totalSumRemainder + p ) % p;
            if (Map.find(r) != Map.end()) {
                
                LL i = Map[r] + 1;
                res = min(res, (LL)(j - i + 1));
            }
            Map[curPrefixSumRemainder] = j;
        }
        
        if (res < nums.size()) {
            return res;
        }
        return -1;
    }
};

// totalSum % p = prefixSum[j] % p - prefixSum[i - 1] % p
//           r0 = r - (r - r0)  