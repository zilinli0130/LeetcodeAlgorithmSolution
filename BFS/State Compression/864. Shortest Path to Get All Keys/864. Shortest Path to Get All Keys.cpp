class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        
        int m = grid.size(), n = grid[0].size(), st = 0, keyCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (islower(grid[i][j])) {
                    keyCount++;
                }
                if (grid[i][j] == '@') {
                    st = i*30+j;
                }
            }
        }
        
        queue<pair<int,int>> q;
        q.push({st, 0});
        vector<pair<int,int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> visited(m*30+n, vector<int>((1<<keyCount),0));
        
        int res = -1;
        while (!q.empty()) {
            
            res++;
            int len = q.size();
            while (len--) {
                
                auto [node, state] = q.front();
                q.pop();
                
                if (visited[node][state]) continue;
                visited[node][state] = 1;
                
                if (state == (1<<keyCount) - 1) {
                    return res;
                }
                
                int j = node % 30;
                int i = (node - j)/30;
                for (int k = 0; k < 4; k++) {
                    
                    int x = i + dirs[k].first;
                    int y = j + dirs[k].second;
                    int next = x*30+y;
                    int nextState = state;
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    if (grid[x][y] == '#') continue;
                    if (grid[x][y] >= 'A' && grid[x][y] <= 'F' && ((state>>(grid[x][y]-'A'))&1) == 0) continue;
                    if (grid[x][y] >= 'a' && grid[x][y] <= 'f') {
                        nextState |= (1<<(grid[x][y]-'a'));
                    }
                    if (visited[next][nextState]) continue;
                    q.push({next, nextState});
                }
            }
        }
        return -1;
    }
};