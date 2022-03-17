class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) 
    {
        int m = toppingCosts.size();
        int res = INT_MAX/2, curDiff = INT_MAX/2;
        for (const auto& baseCost : baseCosts)
        {
            for (int toppingState = 0; toppingState < pow(3,m); toppingState++)
            {
                //Trinary bit
                //get the last bit: %3
                //remove the lasr bit: /3
                int toppingCost = 0;
                int state = toppingState; 
                for (int i = 0; i < m; i++)
                {
                    toppingCost += (state % 3)*toppingCosts[i];
                    state /= 3;
                }
                
                if (abs(baseCost + toppingCost - target) < curDiff)
                {
                    curDiff = abs(baseCost + toppingCost - target);
                    res = baseCost + toppingCost;
                } 
                else if (abs(baseCost + toppingCost - target) == curDiff && baseCost + toppingCost < res)
                {
        
                    res = baseCost + toppingCost;
                }
            }
        }
        return res;
    }
};