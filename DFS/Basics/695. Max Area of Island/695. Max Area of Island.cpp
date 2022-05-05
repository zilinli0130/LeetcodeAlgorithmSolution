class Solution {
    int res = 0;
    int visited[50][50];
    vector<vector<int>> grid;
    vector<pair<int, int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        this->grid = grid;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 1) continue;
                res = max(res, dfs(i,j));
            } 
        }
        return res;
    }
    
    int dfs(int r, int c) {
        
        int count = 1;
        grid[r][c] = 2;
        for (int k = 0; k < 4; k++) {
            
            int x = r + dirs[k].first;
            int y = c + dirs[k].second;
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) continue;
            if (grid[x][y] != 1) continue;
            count += dfs(x,y);
        }
        return count;
    }
};