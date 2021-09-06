class Solution {
    int maxStep;
    int res = 0;
    int memo[1000];
public:
    int maxJumps(vector<int>& arr, int d) {
        
        maxStep = d;
        for (int i = 0; i < arr.size(); i++) {
            res = max(res, dfs(arr, i));
        }
        return res;
    }
    
    int dfs(vector<int>& arr, int currentIdx) {
        
        if (memo[currentIdx] != 0) {
            return memo[currentIdx];
        }
        
        int res = 1;
        //Jump to right
        for (int len = 1; len <= maxStep; len++) {
            if (currentIdx + len >= arr.size()) break;
            if (arr[currentIdx] <= arr[currentIdx + len]) break;
            res = max(res, 1 + dfs(arr, currentIdx + len));
        }
        
        //Jump to left
        for (int len = 1; len <= maxStep; len++) {
            if (currentIdx - len < 0) break;
            if (arr[currentIdx] <= arr[currentIdx - len]) break;
            res = max(res, 1 + dfs(arr, currentIdx - len));
        }
        memo[currentIdx] = res;
        return res;
    }
};