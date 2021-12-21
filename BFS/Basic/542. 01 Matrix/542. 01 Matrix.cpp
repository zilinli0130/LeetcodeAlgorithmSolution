class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        queue<vector<int>> q;
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> res(m, vector<int>(n, INT_MAX/2));
        vector<pair<int, int>> dirs{{0,1},{1,0},{-1,0},{0,-1}};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j, 0});
                }
            }
        }
        
        while (!q.empty()) {
            
            int i = q.front()[0];
            int j = q.front()[1];
            int dist = q.front()[2];
            q.pop();
            
            if (visited[i][j]) continue;
            visited[i][j] = 1;
            
            res[i][j] = min(res[i][j], dist);
            dist++;
            
            for (int k = 0; k < 4; k++) {
                
                int x = i + dirs[k].first;
                int y = j + dirs[k].second;
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                if (mat[x][y] == 0) continue;
                if (visited[x][y]) continue;
                q.push({x, y, dist});
            }
        }
        return res;
    }
};