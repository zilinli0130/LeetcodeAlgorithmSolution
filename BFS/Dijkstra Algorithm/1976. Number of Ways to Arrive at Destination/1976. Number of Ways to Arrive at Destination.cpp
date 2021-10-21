using LL = long long;
typedef pair<LL, LL> PII;
class Solution {
    LL memo[200];
    LL MOD = 1e9 + 7;
    vector<LL> minTime;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        minTime.resize(n,-1);
        memset(memo, -1, sizeof(memo));
        vector<vector<pair<LL, LL>>> Graph(n);
        priority_queue<PII, vector<PII>, greater<>> pq; pq.push({0,0});
        
        for (auto road : roads) {
            Graph[road[0]].push_back({road[2], road[1]});
            Graph[road[1]].push_back({road[2], road[0]});
        }
        
        while (!pq.empty()) {
            
            auto time = pq.top().first;
            auto currentNode = pq.top().second;
            pq.pop();
            
            if (minTime[currentNode] != -1) continue;
            minTime[currentNode] = time;
            
            if (currentNode == n - 1) {
                break;
            }
            
            for (auto item : Graph[currentNode]) {
                
                auto nextTime = item.first;
                auto nextNode = item.second;
                if (minTime[nextNode] != -1) continue;
                pq.push({nextTime + time, nextNode});
            }
        }
        return dfs(Graph, n - 1, minTime[n - 1]);
    }
    
    LL dfs(vector<vector<pair<LL, LL>>>& Graph, LL currentNode, LL currentTime) {
        
        if (minTime[currentNode] != currentTime) {
            return 0;
        }
        
        if (currentTime == 0) {
            return 1;
        }
        
        if (memo[currentNode] != -1) {
            return memo[currentNode];
        }
        
        LL numOfPaths = 0;
        for (auto item : Graph[currentNode]) {
            
            LL ti = item.first;
            int prevNode = item.second;
            numOfPaths += (dfs(Graph, prevNode, currentTime - ti))%MOD;
            numOfPaths %= MOD;
        }
        memo[currentNode] = numOfPaths;
        return numOfPaths;
    }
};