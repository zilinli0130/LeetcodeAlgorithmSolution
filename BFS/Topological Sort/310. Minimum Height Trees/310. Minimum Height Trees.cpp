class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if (n == 1) {
            return {0};
        } else if (n == 2) {
            return {0,1};
        }
        
        queue<int> q;
        vector<int> degrees(n);
        vector<int> visited(n);
        vector<vector<int>> nextNodes(n);
        
        for (auto edge : edges) {
            
            degrees[edge[0]]++;
            degrees[edge[1]]++;
            nextNodes[edge[0]].push_back(edge[1]);
            nextNodes[edge[1]].push_back(edge[0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (degrees[i] == 1) {
                q.push(i);
            }
        }
        
        int count = 0;
        while (!q.empty()) {
            
            int len = q.size();
            while (len--) {
                
                int node = q.front();
                q.pop();
                count++;
                visited[node] = 1;
                for (auto next : nextNodes[node]) {
                    
                    degrees[next]--;
                    if (degrees[next] == 1) {
                        q.push(next);
                    }
                }
            }
            if (count == n - 1 || count == n - 2) {
                break;
            }
        }
        
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};