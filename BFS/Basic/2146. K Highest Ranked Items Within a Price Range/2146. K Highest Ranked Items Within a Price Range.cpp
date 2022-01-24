class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& P, vector<int>& start, int K) {
        
        int dist = 0;
        vector<vector<int>> res;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> distMap(m, vector<int>(n, 0));
        vector<pair<int, int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        
        
        queue<pair<int, int>> queue;
        queue.push({start[0],start[1]});
        while (!queue.empty()) {
            
            int len = queue.size();
            dist++;
            while (len--) {
                
                int i = queue.front().first;
                int j = queue.front().second;
                queue.pop();
                
                if (visited[i][j]) continue;
                visited[i][j] = 1;
                
                if (grid[i][j] > 1 && grid[i][j] >= P[0] && grid[i][j] <= P[1]) {
                    res.push_back({i,j});
                }
                
                
                for (int k = 0; k < 4; k++) {
                    
                    int x = i + dirs[k].first;
                    int y = j + dirs[k].second;
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    if (grid[x][y] == 0) continue;
                    if (visited[x][y]) continue;
                    if (grid[x][y] > 1) {
                        distMap[x][y] = dist;
                    }
                    queue.push({x,y});
                }
            }
        }
        
        sort(begin(res), end(res), [&](vector<int>& a, vector<int>& b) {
            
            if (distMap[a[0]][a[1]] != distMap[b[0]][b[1]]) {
                return distMap[a[0]][a[1]] < distMap[b[0]][b[1]];
            }
            if (grid[a[0]][a[1]] != grid[b[0]][b[1]]) {
                return grid[a[0]][a[1]] < grid[b[0]][b[1]];
            }
            return a < b;
        });
        
        if (res.size() > K) res.resize(K);
        return res;
    }
};