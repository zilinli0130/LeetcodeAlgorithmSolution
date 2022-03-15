class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int res = 0;
        unordered_map<int, int> countMap;
        int l = 0, r = 0, n = fruits.size();
        
        while (l <= r && r < n)
        {
            if (n - l <= res)
            {
                break;
            }
            countMap[fruits[r]]++;
            if (countMap.size() == 3)
            {
                res = max(res, r - l);
                while (countMap.size() != 2)
                {
                    countMap[fruits[l]]--;
                    if (countMap[fruits[l]] == 0)
                    {
                        countMap.erase(fruits[l]);
                    }
                    l++;
                }
            } 
            else {
                res = max(res, r - l + 1);
            }
            r++;
        }
        return res;
    }
};