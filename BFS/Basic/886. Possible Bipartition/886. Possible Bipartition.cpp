class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        queue<int> q;
        vector<int> colors(n + 1, 0);
        vector<vector<int>> Graph(n + 1);
        for (auto& item : dislikes) {
            Graph[item[0]].push_back(item[1]);
            Graph[item[1]].push_back(item[0]);
        }
        
        for (int i = 1; i <= n; i++) {
            if (colors[i] != 0) continue;
            colors[i] = 1;
            q.push(i);
            while (!q.empty()) {
                
                int node = q.front();
                q.pop();
                
                int color = colors[node];
                for (auto& nxt : Graph[node]) {
                    
                    if (colors[nxt] == color) {
                        return false;
                    }
                    if (colors[nxt] == 0) {
                        colors[nxt] = -color;
                        q.push(nxt);
                    }
                }
            }
        }
        return true;
    }
};