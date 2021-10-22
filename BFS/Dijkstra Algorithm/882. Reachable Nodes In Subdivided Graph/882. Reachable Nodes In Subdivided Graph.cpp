typedef pair<int, int> PII;
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        
        vector<int> dist(n, -1);
        vector<vector<PII>> Graph(n);
        priority_queue<PII, vector<PII>, greater<>> pq; pq.push({0,0});
        for (auto edge : edges) {
            Graph[edge[0]].push_back({edge[2] + 1, edge[1]});
            Graph[edge[1]].push_back({edge[2] + 1, edge[0]});
        }
        
        while (!pq.empty()) {
            
            int currentDist = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();
            
            if (dist[currentNode] != -1) continue;
            dist[currentNode] = currentDist;
            
            for (auto item : Graph[currentNode]) {
                if (dist[item.second] != -1) continue;
                if (item.first + currentDist <= maxMoves) {
                    pq.push({item.first + currentDist, item.second});
                }
            }
        }
        
        int res = 0;
        for (auto edge : edges) {
            int node1 = edge[0], node2 = edge[1], cnt = edge[2], count = 0;
            if (dist[node1] != -1)  count += maxMoves - dist[node1];
            if (dist[node2] != -1)  count += maxMoves - dist[node2];
            res += min(cnt, count);
        }
        for (int i = 0; i < n; i++) {
            if (dist[i] == -1) continue;
            res++;
        }
        return res;
    }
};