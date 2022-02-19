class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        int res = INT_MAX/2;
        multiset<int> Set;
        for (auto& num : nums) {
            if (num % 2 == 0) {
                Set.insert(num);
            } else {
                Set.insert(2 * num);
            }
        }
        
        while (true) {
            
            res = min(res, (*Set.rbegin())-(*Set.begin()));
            int curMax = (*Set.rbegin());
            Set.erase(Set.find(curMax));
            if (curMax % 2 == 0) {
                Set.insert(curMax / 2);
            } else {
                break;
            }
        }
        return res;
    }
};