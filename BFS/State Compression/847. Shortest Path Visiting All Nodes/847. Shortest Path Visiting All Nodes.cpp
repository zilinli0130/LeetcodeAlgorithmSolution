class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        queue<pair<int,int>> q; 
        vector<vector<int>> visited(n, vector<int>((1<<n),0));
        
        for (int i = 0; i < n; i++) {
            q.push({i,(1<<i)});
        }
        
        int res = -1;
        while (!q.empty()) {
            
            res++;
            int len = q.size();
            while (len--) {
                
                auto [node, state] = q.front();
                q.pop();
                
                if (visited[node][state]) continue;
                visited[node][state] = 1;
                
                if (state == (1<<n) - 1) {
                    return res;
                }
                
                for (auto& nextNode : graph[node]) {
                    int nextState = state | (1<<nextNode);
                    if (visited[nextNode][nextState]) continue;
                    q.push({nextNode, nextState});
                }
            }
        }
        return 0;
    }
};