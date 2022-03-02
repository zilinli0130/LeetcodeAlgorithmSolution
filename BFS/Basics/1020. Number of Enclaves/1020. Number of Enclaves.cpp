class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<pair<int,int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (grid[i][j] == 1) {
                        q.push({i,j});
                    }
                }
            }
        }
        
        // cout << q.size() << endl;
        while (!q.empty()) {
            
            auto [i,j] = q.front();
            q.pop();
            
            if (visited[i][j]) continue;
            visited[i][j] = 1;
            
            for (int k = 0; k < 4; k++) {
                int x = i + dirs[k].first;
                int y = j + dirs[k].second;
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                if (visited[x][y]) continue;
                if (grid[x][y] == 1) {
                    q.push({x,y});
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    res++;
                }
            }
        }
        return res;
    }
};