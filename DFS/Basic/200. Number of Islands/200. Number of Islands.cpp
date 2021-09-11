class Solution {
    int m, n;
    int res = 0;
    vector<vector<int>> visited;
    vector<pair<int,int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
public:
    int numIslands(vector<vector<char>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        visited.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] || grid[i][j] == '0') continue;
                dfs(grid,i,j);
                res++;
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        
        for (int k = 0; k < 4; k++) {
            int x = i + directions[k].first;
            int y = j + directions[k].second;
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (!visited[x][y] && grid[i][j] == '1') {
                visited[x][y] = 1;
                dfs(grid, x, y);
            }
        }
        return;
    }
};