class Solution {
    int m, n;
    int visited[501][501] = {0};
    vector<pair<int,int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
public:
    bool containsCycle(vector<vector<char>>& grid) {
        
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) continue;
                if (dfs(grid, i, j, -1, -1, 1)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& grid, int i, int j, int prevI, int prevJ, int depth) {
        
        for (int k = 0; k < 4; k++) {
            int x = i + dirs[k].first;
            int y = j + dirs[k].second;
            
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (grid[x][y] != grid[i][j]) continue;
            if (x == prevI && y == prevJ) continue;
            
            if (visited[x][y] == 1 && depth >= 4) {
                return true; 
            }
            visited[x][y] = 1;
            if (dfs(grid, x, y, i, j, depth + 1)) {
                return true;
            }
        }
        return false;
    }
};