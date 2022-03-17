using LL = long long;
typedef pair<LL, LL> PII; 
class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) 
    {
        vector<vector<PII>> Graph(n);
        vector<vector<PII>> invGraph(n);
        
        for (const auto& edge : edges)
        {
            Graph[edge[0]].push_back({edge[1], edge[2]});
            invGraph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<LL> src1ToAllNodes = Dijkstra(src1, Graph);
        vector<LL> src2ToAllNodes = Dijkstra(src2, Graph);
        vector<LL> destToAllNodes = Dijkstra(dest, invGraph);
        
        LL res = LLONG_MAX/3;
        for (int i = 0; i < n; i++)
        {
            res = min(res, src1ToAllNodes[i] + src2ToAllNodes[i] + destToAllNodes[i]);
        }
        return res == LLONG_MAX/3 ? -1 : res;
    }
    
    vector<LL> Dijkstra(int start, vector<vector<PII>>& Graph)
    {
        vector<LL> res(Graph.size(), LLONG_MAX/3);
        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.push({0, start});
        
        while (!pq.empty())
        {
            auto [cost, curNode] = pq.top();
            pq.pop();

            if (res[curNode] < LLONG_MAX/3) 
            {
                continue;
            }
            res[curNode] = cost;
            
            for (const auto& next : Graph[curNode])
            {
                if (res[next.first] < LLONG_MAX/3)
                {
                    continue;
                }
                pq.push({cost + next.second, next.first});
            }
        }
        return res;
    }
};