class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<pair<int, int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0) {
                grid[0][j] = -1;
            }
        }
        for (int j = 0; j < n; j++) {
            if (grid[m - 1][j] == 0) {
                grid[m - 1][j] = -1;
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                grid[i][0] = -1;
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[i][n - 1] == 0) {
                grid[i][n - 1] = -1;
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) continue;
                if (visited[i][j]) continue;
                
                int flag = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    
                    if (visited[r][c]) continue;
                    visited[r][c] = 1;
                    
                    if (grid[r][c] == -1) {
                        flag = 1;
                    }
                    
                    for (int k = 0; k < 4; k++) {
                        int x = r + dirs[k].first;
                        int y = c + dirs[k].second;
                        if (x < 0 || x >= m || y < 0 || y >= n) continue;
                        if (visited[x][y]) continue;
                        if (grid[x][y] == 1) continue;
                        q.push({x,y});
                    }
                }
                if (!flag) {
                    res++;
                }
            }
        }
        return res;
    }
};