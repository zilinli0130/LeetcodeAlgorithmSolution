class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int prefixSum = 0, res = 0;
        unordered_map<int, int> Map;
        Map[0] = 1;
        
        for (const auto& num : nums) {
            
            prefixSum += num;
            int remainder = prefixSum > 0 ? prefixSum % k : (prefixSum % k + k) % k;
            res += Map[remainder];
            Map[remainder]++;
        }
        return res;
    }
};

    
    
