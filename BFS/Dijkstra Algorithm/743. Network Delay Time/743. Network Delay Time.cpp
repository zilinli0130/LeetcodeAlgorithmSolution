class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int res = 0;
        int numOfVisited = 0;
        vector<int> visited(n + 1);
        vector<vector<pair<int, int>>> Graph(n + 1);
        for (auto item : times) {
            int source = item[0];
            int target = item[1];
            int cost = item[2];
            Graph[source].push_back(pair<int, int>{cost, target});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push(pair<int, int>{0, k});
        
        while (!pq.empty()) {
            
            int cost = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();
            
            if (visited[currentNode]) continue;
            visited[currentNode] = 1;
            numOfVisited++;
            
            res = max(res, cost);
            
            if (numOfVisited == n) {
                return res;
            }
            
            
            for (auto item : Graph[currentNode]) {
                
                int nextCost = item.first;
                int nextNode = item.second;
                if (visited[nextNode]) continue;
                pq.push(pair<int, int>{cost + nextCost, nextNode});
            }
        }
        return -1;
    }
};