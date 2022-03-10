class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k)
    {
        
        if (nums.size() < k) 
        {
            return false;
        }
        
        sort(nums.begin(), nums.end());
        unordered_map<int, int> numCount;
        for (const auto& num : nums)
        {
            numCount[num]++;
        }
        
        for (const auto& num : nums) {
            
            if (numCount[num] == 0) 
            {   
                continue;
            }
            
            for (int i = 1; i < k; i++)
            {   
                
                if (numCount[num + i] == 0)
                {   
                    return false;
                }
            }
            
            numCount[num]--;
            for (int i = 1; i < k; i++)
            {
                numCount[num + i]--;
            } 
        }
        return true;
    }
};