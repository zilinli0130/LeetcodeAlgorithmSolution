class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int res = 0;
        int prefixSum = 0;
        unordered_map<double, int> Map;
        Map[0] = -1;
        
        
        for (int j = 0; j < nums.size(); j++) {
            
            prefixSum += (nums[j] == 1? 1 : -1);
            if (Map.find(prefixSum) != Map.end()) {
                res = max(res, j - Map[prefixSum]);
            }
            if (Map.find(prefixSum) == Map.end()) {
                Map[prefixSum] = j;
            } else {
                Map[prefixSum] = min(Map[prefixSum], j);
            }
        }               
        return res;
    }
};

// -1-2-1-2-3-4-3-2
// [0,0,1,0,0,0,1,1]
