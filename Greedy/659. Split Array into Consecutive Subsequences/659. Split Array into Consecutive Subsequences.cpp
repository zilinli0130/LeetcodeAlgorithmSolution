class Solution {
public:
    bool isPossible(vector<int>& nums) 
    {
        unordered_map<int,int> seqCount;
        unordered_map<int,int> numCount;
        for (const auto& num : nums)
        {
            numCount[num]++;
        }
        
        for (const auto& num : nums) 
        {
            if (numCount[num] == 0) 
            {
                continue;
            }
            
            if (seqCount[num - 1] != 0)
            {
                numCount[num]--;
                seqCount[num - 1]--;
                seqCount[num]++;
            }
            else 
            {
                if (numCount[num + 1] == 0 || numCount[num + 2] == 0)
                {
                    return false;
                }
                
                numCount[num]--;
                numCount[num + 1]--;
                numCount[num + 2]--;
                seqCount[num + 2]++;
            }
        }
        return true;
    }
};