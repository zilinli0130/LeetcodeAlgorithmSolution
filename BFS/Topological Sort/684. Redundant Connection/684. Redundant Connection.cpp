class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> degree(n + 1, 0);
        vector<int> visited(n + 1, 0);
        vector<vector<int>> nexts(n + 1);
        
        for (int i = 0; i < n; i++) {
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
            nexts[edges[i][0]].push_back(edges[i][1]);
            nexts[edges[i][1]].push_back(edges[i][0]);   
        }
        
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 1) {
                q.push(i);
                visited[i] = 1;
            }
        }
        
        while (!q.empty()) {
            
            int curNode = q.front();
            q.pop();
            
            for (auto next : nexts[curNode]) {
                if (visited[next]) continue;
                degree[next]--;
                if (degree[next] == 1) {
                    q.push(next);
                    visited[next] = 1;
                }
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (visited[edges[i][0]] == 0 && visited[edges[i][1]] == 0) {
                return edges[i];
            }
        }
        return {};
    }
};