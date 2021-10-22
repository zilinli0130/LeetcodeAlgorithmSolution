using LL = long long;
typedef pair<LL, LL> PII;
class Solution {
    LL memo[20001];
    LL dist[20001];
    LL visited[20001];
     vector<PII> Graph[20001];
    LL MOD = 1e9 + 7;
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        priority_queue<PII, vector<PII>, greater<>> pq; pq.push({0,n});
        
        for (auto edge : edges) {
            Graph[edge[0]].push_back({edge[2], edge[1]});
            Graph[edge[1]].push_back({edge[2], edge[0]});
        }
        
        while (!pq.empty()) {
            
            LL d = pq.top().first;
            LL node = pq.top().second;
            pq.pop();
            
            if (visited[node]) continue;
            dist[node] = d;
            visited[node] = 1;
            
            for (auto item: Graph[node]) {
                if (visited[item.second]) continue;
                pq.push({d + item.first, item.second});
            }
        }
        
        for (int i = 1; i <= n; i++) {
            memo[i] = -1;
        }
        return dfs(n);
    }
    
    LL dfs(int currentNode) {
        
        if (currentNode == 1) {
            return 1;
        }
        
        if (memo[currentNode] != -1) {
            return memo[currentNode];
        }
        
        LL res = 0;
        for (auto item : Graph[currentNode]) {
            int lastNode = item.second;
            if (dist[currentNode] >= dist[lastNode]) continue;
            res += dfs(lastNode);
            res %= MOD;
        }
        memo[currentNode] = res;
        return res;
    }
};
