typedef pair<int,int> PII;
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        queue<PII> q;
        q.push({entrance[0], entrance[1]});
        int m = maze.size(), n = maze[0].size();
        vector<PII> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        
        int res = -1;
        while (!q.empty()) {
            
            res++;
            int len = q.size();
            while (len--) {
                
                auto [i, j] = q.front();
                q.pop();
                
                if (maze[i][j] == '-') continue;
                maze[i][j] = '-';
                
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (res > 0) {
                        return res;
                    }
                }
                for (int k = 0; k < 4; k++) {
                    
                    int x = i + dirs[k].first;
                    int y = j + dirs[k].second;
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    if (maze[x][y] != '.') continue;
                    q.push({x,y});
                }
            }
        }
        return -1;
    }
};