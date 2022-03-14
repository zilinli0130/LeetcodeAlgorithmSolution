class Solution {
    string labels;
    vector<int> res;
    vector<int> visited;
    vector<vector<int>> Graph;
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)
    {
        
        Graph.resize(n);
        res.resize(n, 1);
        visited.resize(n, 0);
        this->labels = labels;
        
        for (const auto& edge : edges)
        {
            Graph[edge[0]].push_back(edge[1]);
            Graph[edge[1]].push_back(edge[0]);  
        }
        visited[0] = 1;
        dfs(0);
        return res;
    }
    
    unordered_map<char,int> dfs(int curNode)
    {
        unordered_map<char, int> globalMap;        
        char label = labels[curNode];
        globalMap[label]++;
        for (const auto& nextNode : Graph[curNode])
        {
            if (visited[nextNode] == 1)
            {
                continue;
            }
            visited[nextNode] = 1;
            unordered_map<char, int> localMap = dfs(nextNode);
            res[curNode] += localMap[label];
            for (const auto& item : localMap)
            {
                globalMap[item.first] += item.second;
            }
        }
        return globalMap;
    }
};