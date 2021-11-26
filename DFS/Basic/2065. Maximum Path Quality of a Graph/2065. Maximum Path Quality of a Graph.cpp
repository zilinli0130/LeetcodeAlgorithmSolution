typedef pair<int, int> PII;
class Solution {
    int res = 0;
    int maxTime;
    vector<int> values;
    vector<int> visited;
    vector<vector<PII>> Graph;
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        
        this->values = values;
        this->maxTime = maxTime;
        Graph.resize(values.size());
        visited.resize(values.size(), 0);
        
        for (auto edge : edges) {
            Graph[edge[0]].push_back({edge[1], edge[2]});
            Graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        visited[0] = 1;
        dfs(0, values[0], 0);
        return res;
    }
    
    void dfs(int curNode, int curQuality, int curTime) {
        
        if (curTime > maxTime) {
            return;
        }
        if (curNode == 0) {
            res = max(res, curQuality);
        } 
        
        for (auto next : Graph[curNode]) {
            visited[next.first]++;
            dfs(next.first, curQuality + (visited[next.first] == 1? values[next.first] : 0), curTime + next.second);
            visited[next.first]--;
        }
    }
};