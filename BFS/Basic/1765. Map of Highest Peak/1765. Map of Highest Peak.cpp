class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int m = isWater.size(), n = isWater[0].size();
        queue<pair<int,int>> q; 
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<pair<int,int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i,j});
                    isWater[i][j] = -1;
                }
            }
        }
        
        int h = -1;
        while (!q.empty()) {
            
            h++;
            int len = q.size();
            while (len--) {
                
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                if (visited[i][j]) continue;
                visited[i][j] = 1;
                isWater[i][j] = h;
                
                for (int k = 0; k < 4; k++) {
                    int x = i + dirs[k].first;
                    int y = j + dirs[k].second;
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    if (visited[x][y]) continue;
                    q.push({x,y});
                }
            }
        }
        return isWater;
    }
};
