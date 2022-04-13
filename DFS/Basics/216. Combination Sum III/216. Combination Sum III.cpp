class Solution {
    int n;
    int k;
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        this->n = n;
        this->k = k;
        vector<int> comb;
        dfs(comb, 0, 1);
        return res;
    }
    
    void dfs(vector<int>& comb, int curSum, int curInt) {
        
        if (curSum == n && comb.size() == k) {
            res.push_back(comb);
            return;
        }
        
        if (curSum > n || curInt > 9 || comb.size() > k) {
            return;
        }
        
        for (int i = curInt; i <= 9; i++) {
            comb.push_back(i);
            dfs(comb, curSum + i, i + 1);
            comb.pop_back();
        }
    }
};