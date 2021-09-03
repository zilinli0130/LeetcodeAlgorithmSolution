class Solution {
    int res = 0;
    int memo[200][200];
    vector<pair<int, int>> directions{{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                res = max(res, 1 + dfs(matrix, i, j));
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        
        int res = 0;
        for (int k = 0; k < 4; k++) {
            int x = i + directions[k].first;
            int y = j + directions[k].second;
            if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()) continue;
            if (matrix[i][j] >= matrix[x][y]) continue;
            res = max(res, 1 + dfs(matrix, x, y));
        }
        memo[i][j] = res;
        return res;
    }
};