using LL = long long;
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int res = 0;
        int n = bombs.size();

        for (int i = 0; i < n; i++) {

            vector<int> visited(n, 0);
            vector<int> temp = bombs[i];
            temp.push_back(i);
            queue<vector<int>> q;
            q.push(temp);
            int count = 0;

            while (!q.empty()) {

                int x1 = q.front()[0];
                int y1 = q.front()[1];
                int r1 = q.front()[2];
                int idx = q.front()[3];
                q.pop();

                if (visited[idx]) continue;
                visited[idx] = 1;
                count++;

                for (int i = 0; i < n; i++) {

                    if (visited[i]) continue;
                    int x2 = bombs[i][0];
                    int y2 = bombs[i][1];
                    int r2 = bombs[i][2];
                    int idx2 = i;
                    LL dx = x1 - x2;
                    LL dy = y1 - y2;
                    LL r = r1;

                    if (dx*dx + dy*dy <= r*r) {
                        q.push({x2,y2,r2,idx2});
                    }
                }
            }
            res = max(res, count);
        }  
        return res;
    }
};