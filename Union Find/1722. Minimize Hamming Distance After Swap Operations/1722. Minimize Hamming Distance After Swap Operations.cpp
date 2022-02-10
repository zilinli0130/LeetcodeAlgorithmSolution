class Solution {
    int Ancestor[100001];
    int FindAncestor(int x) {
        if (Ancestor[x] != x) {
            Ancestor[x] = FindAncestor(Ancestor[x]);
        }
        return Ancestor[x];
    }
    void Union(int x, int y) {
        x = Ancestor[x];
        y = Ancestor[y];
        if (x < y) {
            Ancestor[y] = x;
        } else {
            Ancestor[x] = y;
        }
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        const int n = source.size();
        for (int i = 0; i < n; i++) {
            Ancestor[i] = i;
        }
        
        for (auto item : allowedSwaps) {
            if (FindAncestor(item[0]) != FindAncestor(item[1])) {
                Union(item[0],item[1]);
            }
        }
        
        unordered_map<int, vector<int>> unionMap;
        for (int i = 0; i < n; i++) {
            unionMap[FindAncestor(i)].push_back(i);
        }
        
        int res = 0;
        for (auto item : unionMap) {
            
            multiset<int> Set;
            for (auto i : item.second) {
                Set.insert(source[i]);
            }
            for (auto i : item.second) {
                if (Set.find(target[i]) != Set.end()) {
                    Set.erase(Set.lower_bound(target[i]));
                }
            }
            res += Set.size();
        }
        return res;
    }
};