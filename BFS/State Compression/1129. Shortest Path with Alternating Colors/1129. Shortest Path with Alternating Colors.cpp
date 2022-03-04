typedef pair<int,int> PII;
class Solution {
    int visited[101][3];
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        //red->0, blue->1
        vector<int> res(n, -1);
        res[0] = 0;
        queue<PII> q;        
        vector<vector<int>> redGraph(n);
        vector<vector<int>> blueGraph(n);
        
        for (auto& edge : redEdges) {
            redGraph[edge[0]].push_back(edge[1]);
        }
        
        for (auto& edge : blueEdges) {
            blueGraph[edge[0]].push_back(edge[1]);
        }
        
        int step = -1;
        q.push({0,2});
        while (!q.empty()) {
            
            step++;
            int len = q.size();
            while (len--) {
                
                auto [curNode, color] = q.front();
                q.pop();
                
                if (visited[curNode][color]) continue;
                visited[curNode][color] = 1;
                
                if (res[curNode] > 0) {
                    res[curNode] = min(res[curNode], step);
                } else {
                    res[curNode] = step;
                }
                
                if (color == 0) {
                    for (auto& nextNode : blueGraph[curNode]) {
                        if (nextNode == 0) continue;
                        if (visited[nextNode][1]) continue;
                        q.push({nextNode,1});
                    }
                } else if (color == 1) {
                    for (auto& nextNode : redGraph[curNode]) {
                        if (nextNode == 0) continue;
                        if (visited[nextNode][0]) continue;
                        q.push({nextNode,0});
                    }
                } else if (color == 2 && curNode == 0) {
                    for (auto& nextNode : redGraph[curNode]) {
                        if (nextNode == 0) continue;
                        if (visited[nextNode][0]) continue;
                        q.push({nextNode,0});
                    }
                    for (auto& nextNode : blueGraph[curNode]) {
                        if (nextNode == 0) continue;
                        if (visited[nextNode][1]) continue;
                        q.push({nextNode,1});
                    }
                }
                
            }
        }
        return res;
    }
};

