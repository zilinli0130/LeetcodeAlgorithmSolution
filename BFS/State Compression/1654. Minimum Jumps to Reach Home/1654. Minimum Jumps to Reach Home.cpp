class Solution {
    int visited[10000][2];
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        if (x == 0) return 0;
        
        int maxForbidden = *max_element(forbidden.begin(), forbidden.end());
        int limit = max(x, maxForbidden) + b;
        for (auto& item : forbidden) {
            visited[item][0] = -1;
            visited[item][1] = -1;
        }
        
        int res = -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        while (!q.empty()) {
            
            res++;
            int len = q.size();
            while (len--) {
                
                auto [pos, dir] = q.front();
                q.pop();
                
                if (visited[pos][dir]) continue;
                visited[pos][dir] = 1;
                
                if (pos == x) {
                    return res;
                }
                
                if (pos <= limit && visited[pos + a][0] == 0) {
                    q.push({pos + a, 0});
                }
                if (dir == 0 && pos - b >= 0 && visited[pos - b][1] == 0) {
                    q.push({pos - b, 1});
                }
            }
        }
        return -1;
    }
};