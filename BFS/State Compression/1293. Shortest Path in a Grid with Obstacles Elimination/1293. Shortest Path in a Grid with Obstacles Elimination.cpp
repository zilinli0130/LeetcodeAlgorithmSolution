class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int m = grid.size(), n = grid[0].size();
        vector<pair<int,int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> visited(m * 40 + n, vector<int>(k + 1,0));    
        queue<pair<int, int>> q;
        q.push({0,k});
        
        int res = -1;
        while (!q.empty()) {
            
            res++;
            int len = q.size();
            while (len--) {
                
                auto [node, curStep] = q.front();
                q.pop();
                
                int j = node % 40;
                int i = (node - j) / 40;
                
                if (visited[node][curStep]) continue;
                visited[node][curStep] = 1;
                
                if (i == m - 1 && j == n - 1) {
                    return res;
                }
                
                for (int k = 0; k < 4; k++) {
                    
                    int x = i + dirs[k].first;
                    int y = j + dirs[k].second;
                    int nextStep = curStep;
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    if (grid[x][y] == 1) {
                        if (nextStep == 0) continue;
                        nextStep--;
                    }
                    if (visited[x * 40 + y][nextStep]) continue;
                    q.push({x * 40 + y, nextStep});
                }
            }  
        }
        return -1;
    }
};
