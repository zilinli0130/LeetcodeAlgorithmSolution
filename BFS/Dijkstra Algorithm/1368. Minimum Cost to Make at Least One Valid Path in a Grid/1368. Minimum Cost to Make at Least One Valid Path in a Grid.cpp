typedef vector<int> VI; 
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> minCost(m, vector<int>(n, INT_MAX/2));
        vector<pair<int, int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<VI, vector<VI>, greater<>> pq;
        pq.push({0,0,0});
        minCost[0][0] = 0;
 
        while (!pq.empty()) {
            
            int i = pq.top()[1];
            int j = pq.top()[2];
            int currentCost = pq.top()[0];
            pq.pop();
            
            if (visited[i][j]) continue;
            visited[i][j] = 1;
            
            if (i == m - 1 && j == n - 1) {
                return minCost[i][j];
            }
            
            
            for (int k = 0; k < 4; k++) {
                
                int x = i + directions[k].first;
                int y = j + directions[k].second;
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                if (visited[x][y]) continue;
                
                if (grid[i][j] == 1 && j + 1 != y) {
                     minCost[x][y] = min(minCost[x][y], currentCost + 1);
                } else if (grid[i][j] == 2 && j - 1 != y) {
                     minCost[x][y] = min(minCost[x][y], currentCost + 1); 
                } else if (grid[i][j] == 3 && i + 1 != x) {
                     minCost[x][y] = min(minCost[x][y], currentCost + 1);
                } else if (grid[i][j] == 4 && i - 1 != x) {
                     minCost[x][y] = min(minCost[x][y], currentCost + 1);
                } else {
                     minCost[x][y] = min(minCost[x][y], currentCost);
                }
                pq.push({minCost[x][y], x, y});
            }  
        }
        return -1;
    }
};





