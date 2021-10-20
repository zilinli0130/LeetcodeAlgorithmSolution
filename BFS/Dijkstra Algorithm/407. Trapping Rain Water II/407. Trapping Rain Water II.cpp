typedef vector<int> VT;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int res = 0;
        int seaLevel = INT_MIN/2;
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        priority_queue<VT, vector<VT>, greater<>> pq;
        vector<pair<int, int>> directions{{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], i, j});
                }
            }
        }
        
        while (!pq.empty()) {
        
            int currentHeight = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            
            if (visited[x][y]) continue;
            visited[x][y] = 1;
            
            if (seaLevel < currentHeight) {
                seaLevel = currentHeight;
            }
            
            res += seaLevel - currentHeight;
            
            for (int k = 0; k < 4; k++) {
                
                int i = x + directions[k].first;
                int j = y + directions[k].second;
                if (i < 0 || i > m-1 || j < 0 || j > n - 1) continue;
                if (visited[i][j]) continue;
                pq.push({heightMap[i][j], i, j});
            }
        }
        return res;
    }
};

/*
Dijkstra algorithm

1. It visits all the nodes whose height are less than the 
current sea level and pours water onto these nodes. 

2. It would visit all the nodes whose height are equal to the current sear level. 

3. It would update the current sea level to a higher sea level

*/