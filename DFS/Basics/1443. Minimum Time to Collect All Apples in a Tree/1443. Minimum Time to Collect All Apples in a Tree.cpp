class Solution {
    int numOfApple = 0;
    vector<int> visited;
    vector<bool> hasApple;
    vector<vector<int>> Graph;
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        Graph.resize(n);
        visited.resize(n,0);
        this->hasApple = hasApple;
        
        for (int i = 0; i < n; i++) {
            numOfApple += (hasApple[i] == true); 
        }
        if (numOfApple == 0) {
            return 0;
        }
        
        for (auto& edge : edges) {
            Graph[edge[0]].push_back(edge[1]);
            Graph[edge[1]].push_back(edge[0]);
        }
        
        visited[0] = 1;
        return dfs(0);
    }
    
    int dfs(int curNode) {
        
        int res = 0;
        for (auto& nextNode : Graph[curNode]) {
            
            if (visited[nextNode]) continue;
            
            visited[nextNode] = 1;
            if (hasApple[nextNode] == 1) {
                res += 2;
            }
            
            int nextRes = dfs(nextNode);
            if (nextRes != 0) {
                if (hasApple[nextNode] != 1) {
                    res += 2;
                }
                res += nextRes;
            }
            visited[nextNode] = 0;
        }
        return res;
    }
};