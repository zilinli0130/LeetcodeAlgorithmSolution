typedef pair<int,int> PII;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        vector<int> res;
        multiset<PII> Set;
        int n = nums.size();
        int range = INT_MAX/2;
        vector<int> index(n, 0);
        
        for (int i = 0; i < n; i++) {
            Set.insert({nums[i][0],i});
        }
        
        while (1) {
            
            if (Set.rbegin()->first - Set.begin()->first < range) {
                range = Set.rbegin()->first - Set.begin()->first;
                res = {Set.begin()->first, Set.rbegin()->first};
            }
            int group = Set.begin()->second;
            Set.erase(Set.begin());
            index[group]++;
            if (index[group] == nums[group].size()) {
                break;
            }
            Set.insert({nums[group][index[group]], group});
        }
        return res;
    }
};
