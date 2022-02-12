class Solution {
    int m, n;
    int res = 0;
    vector<pair<int, int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        m = grid1.size(), n = grid1[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1) {
                    bfs(grid1, grid2, i, j);
                }
            }
        }
        return res;
    }
    
    void bfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2, int i, int j) {
        
        queue<pair<int, int>> q;
        q.push({i,j});
        
        int flag = 1;
        while (!q.empty()) {
            
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            if (grid1[i][j] != 1) {
                flag = 0;
            }
            
            if (grid2[i][j] == 2) continue;
            grid2[i][j] = 2;
            
            
            for (int k = 0; k < 4; k++) {
                int x = i + dirs[k].first;
                int y = j + dirs[k].second;
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                if (grid2[x][y] == 0) continue;
                q.push({x,y});
            }
        }
        res += flag == 1? 1 : 0;
        return;
    }
};