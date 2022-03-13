class Solution {
    int m, n;
    vector<vector<int>> heights;
    
    vector<pair<int,int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        this->heights = heights;
        m = heights.size(), n = heights[0].size();
        vector<vector<int>> visitedPac(m, vector<int>(n, 0));
        vector<vector<int>> visitedAta(m, vector<int>(n, 0));
        
        
        for (int i = 0; i < m; i++) {
            dfs(i,0,visitedPac);
        } 
        for (int j = 0; j < n; j++) {
            dfs(0,j,visitedPac);
        } 
        for (int i = 0; i < m; i++) {
            dfs(i,n - 1,visitedAta);
        } 
        for (int j = 0; j < n; j++) {
            dfs(m - 1,j,visitedAta);
        } 
        
        vector<vector<int>>res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visitedPac[i][j] == 1 && visitedAta[i][j] == 1) {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
    
    void dfs(int r, int c, vector<vector<int>>& visited) {

        visited[r][c] = 1;
        for (int k = 0; k < 4; k++) {
            
            int x = r + dirs[k].first;
            int y = c + dirs[k].second;
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (heights[x][y] < heights[r][c]) continue;
            if (visited[x][y]) continue;
            dfs(x, y, visited);
        }
    }
};