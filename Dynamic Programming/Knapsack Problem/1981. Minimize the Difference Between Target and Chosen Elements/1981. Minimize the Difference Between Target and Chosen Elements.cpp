class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) 
    {
        unordered_set<int> Set({0});
        int res = INT_MAX, m = mat.size(), n = mat[0].size();
        
        for (int i = 0; i < m; i++)
        {
            unordered_set<int> newSet;
            int minGreaterThanTarget = -1;
            for (const auto& num1 : Set)
            {
                for (const auto& num2 : mat[i])
                {
                    if (num1 + num2 <= target)
                    {
                        newSet.insert(num1 + num2);
                    }
                    else
                    {
                        if (minGreaterThanTarget == -1 || num1 + num2 < minGreaterThanTarget)
                        {
                            minGreaterThanTarget = num1 + num2;
                        }
                    }
                }
            }
            if (minGreaterThanTarget != -1)
            {
                newSet.insert(minGreaterThanTarget);
            }
            Set = std::move(newSet);
        }
        
        for (const auto& num : Set)
        {
            res = min(res, abs(target - num));
        }
        return res;
    }
};