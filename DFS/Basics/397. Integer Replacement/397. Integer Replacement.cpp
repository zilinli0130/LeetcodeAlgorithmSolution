class Solution {
    int res = INT_MAX;
public:
    int integerReplacement(int n) {
        
        dfs(n, 0);
        return res;
    }
    
    void dfs(long curNum, int ops) {
        
        if (curNum == 1) {
            res = min(res, ops);
            return;
        }
        
        if (curNum % 2 == 0) {
            dfs(curNum/2, ops + 1);
        } else if (curNum % 2 == 1) {
            dfs(curNum - 1, ops + 1);
            dfs(curNum + 1, ops + 1);
        }
    }
};