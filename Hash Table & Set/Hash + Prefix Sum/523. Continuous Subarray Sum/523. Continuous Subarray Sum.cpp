class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        if (nums.size() <= 1) {
            return false;
        }
        
        int prefixSum = 0;
        int n = nums.size();
        unordered_map<int,int> Map;
        Map[0] = -1;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            prefixSum %= k;
            
            if (Map.find(prefixSum) != Map.end()) {
                if (i - Map[prefixSum] >= 2) {
                    return true;
                }
            } else {
                Map[prefixSum] = i;
            }
        }
        return false;
    }
};

// i X X X X X X X j

// presum[i - 1]%k + (i,j)%k = presum[j]%k
