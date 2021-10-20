typedef vector<int> VI;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int totalTime = 0;
        int n = grid.size();
        int previousTime = 0;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<pair<int, int>> directions{{0,1}, {0,-1}, {1,0}, {-1,0}};
        priority_queue<VI, vector<VI>, greater<VI>>pq;
        pq.push({grid[0][0], 0, 0}); 
        
        while (!pq.empty()) {
            
            int x = pq.top()[1];
            int y = pq.top()[2];
            int currentTime = pq.top()[0];
            pq.pop();
            
            if (visited[x][y]) continue;
            visited[x][y] = 1;
            
            int waitTime = 0;
            if (currentTime > previousTime) {
                waitTime = currentTime - previousTime;
                previousTime = currentTime;
            }
            
            totalTime += waitTime;
            
            if (x == n - 1 && y == n - 1) {
                return totalTime;
            }
            
            for (int k = 0; k < 4; k++) {
                
                int i = x + directions[k].first;
                int j = y + directions[k].second;
                if (i < 0 || i >= n || j < 0 || j >= n) continue;
                if (visited[i][j]) continue;
                pq.push({grid[i][j], i, j});
            }
        }
        return -1; 
    }
};