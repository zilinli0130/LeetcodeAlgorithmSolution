class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        
        unordered_map<int, vector<vector<int>>> Map;
        Map[1] = {{0,1},{0,-1}};
        Map[2] = {{1,0},{-1,0}};
        Map[3] = {{0,-1},{1,0}};
        Map[4] = {{0,1},{1,0}};
        Map[5] = {{0,-1},{-1,0}};
        Map[6] = {{0,1},{-1,0}};
        
        queue<pair<int, int>> q;
        q.push({0,0});
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        
        while (!q.empty()) {
            
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            if (r == grid.size() - 1 && c == grid[0].size() - 1) return true;
            if (visited[r][c]) continue;
            visited[r][c] = 1;
            
            for (int k = 0; k < 2; k++) {
                
                int x = r + Map[grid[r][c]][k][0];
                int y = c + Map[grid[r][c]][k][1];
                if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) continue;
                if (visited[x][y]) continue;
                
                int p1 = x + Map[grid[x][y]][0][0];
                int p2 = y + Map[grid[x][y]][0][1];
                int p3 = x + Map[grid[x][y]][1][0];
                int p4 = y + Map[grid[x][y]][1][1];
                
                if ((p1 == r && p2 == c) || (p3 == r && p4 == c)) {
                    q.push({x,y});
                }
            }
        }
        return false;
    }
};