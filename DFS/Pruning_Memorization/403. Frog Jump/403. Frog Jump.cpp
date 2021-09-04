class Solution {
    int lastStone;
    unordered_set<int> Set;
    set<pair<int, int>> memo;

public:
    bool canCross(vector<int>& stones) {
        
        lastStone = stones.back();
        for (auto stone : stones) {
            Set.insert(stone);
        }
        return dfs(0, 0);
    }
    
    bool dfs(int pos, int k) {
        
        if (pos == lastStone) {
            return true;
        }
        if (Set.find(pos) == Set.end()) {
            return false;
        }
        if (memo.find(pair<int, int>{pos, k}) != memo.end()) {
            return false;
        }
        
        //Three ways
        if (k > 1 && dfs(pos + k - 1, k - 1)) {
            return true;
        }
        if (k > 0 && dfs(pos + k, k)) {
            return true;
        }
        if (dfs(pos + k + 1, k + 1)) {
            return true;
        }
        memo.insert(pair<int, int>{pos, k});
        return false;
    }
};