typedef pair<int, int> PII;
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        int res = 0;
        vector<int> InDegree(n + 1, 0);
        vector<vector<int>> Graph(n + 1);
        priority_queue<PII, vector<PII>, greater<>> pq;
        for (auto relation : relations) {
            int prev = relation[0];
            int next = relation[1];
            Graph[prev].push_back(next); //prev->next
            InDegree[next]++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (InDegree[i] == 0) {
                pq.push({time[i - 1], i});
            }
        }
        
        while (!pq.empty()) {
            
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            res = max(res, t);
            
            for (auto next : Graph[node]) {
                
                InDegree[next]--;
                if (InDegree[next] == 0) {
                    pq.push({t + time[next - 1], next});
                }
            }
        }
        return res;
    }
};