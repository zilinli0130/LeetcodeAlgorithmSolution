using PII = pair<int, int>;
class Solution {
    int visited[1001];
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<vector<PII>> edges(n);
        
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges[i].push_back({dist,j});
                edges[j].push_back({dist,i});
            }
        }
        
        int res = 0;
        int count = 1;
        visited[0] = 1;
        priority_queue<PII, vector<PII>, greater<>> pq(edges[0].begin(), edges[0].end());
        
        while (count < n) {
            
            while (!pq.empty() && visited[pq.top().second] == 1) {
                pq.pop();
            }
            auto item = pq.top();
            pq.pop();
            visited[item.second] = 1;
            res += item.first;
            count++;
            
            for (auto edge : edges[item.second]) {
                pq.push(edge);
            }
        }
        return res;
    }
};