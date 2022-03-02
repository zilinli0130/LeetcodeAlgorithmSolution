class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int res = -1;
        int step = -1;
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i,j});
                    grid[i][j] = 2;
                }
            }
        }
        
        while (!q.empty()) {
            
            int len = q.size();
            step++;
            while (len--) {
                
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for (int k = 0; k < 4; k++) {
                    
                    int x = i + dirs[k].first;
                    int y = j + dirs[k].second;
                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    if (grid[x][y] == 2) continue;
                    res = max(res, step + 1);
                    grid[x][y] = 2;
                    q.push({x,y});
                }
            }
        }
        return res;
    }
};