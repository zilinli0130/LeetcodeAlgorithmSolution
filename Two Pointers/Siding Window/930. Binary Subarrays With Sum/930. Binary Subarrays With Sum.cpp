class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int, int> Map; //prefix - S, number
        Map[0] = 1;
        
        int res = 0;
        int prefix = 0;
        for (int j = 0; j < nums.size(); j++) {
            
            prefix += nums[j];
            if (Map.find(prefix - goal) != Map.end()) {
                res += Map[prefix - goal];
            }
            Map[prefix]++;
        }
        return res;
    }
};

//Hash + Prefix Sum

