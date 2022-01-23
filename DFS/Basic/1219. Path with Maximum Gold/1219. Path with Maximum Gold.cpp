class Solution {
    int m, n;
    vector<vector<int>> grid;
    vector<pair<int, int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int res = 0;
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                vector<vector<int>> visited(m, vector<int>(n, 0));
                visited[i][j] = 1;
                res = max(res, grid[i][j] + dfs(visited,i,j));
                visited[i][j] = 0;
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& visited, int r, int c) {
        
        int res = 0;
        for (int k = 0; k < 4; k++) {
            int x = r + dirs[k].first;
            int y = c + dirs[k].second;
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (grid[x][y] == 0) continue;
            if (visited[x][y]) continue;
            visited[x][y] = 1;
            res = max(res, grid[x][y] + dfs(visited,x,y));
            visited[x][y] = 0;
        }
        return res;
    }
};