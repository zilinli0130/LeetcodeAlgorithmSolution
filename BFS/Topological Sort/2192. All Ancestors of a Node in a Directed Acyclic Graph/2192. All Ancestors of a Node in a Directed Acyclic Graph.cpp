class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> res;
        vector<int> inDegrees(n);
        vector<set<int>> setRes(n);
        vector<vector<int>> Graph(n);
        
        for (const auto& edge : edges)
        {
            Graph[edge[0]].push_back(edge[1]);
            inDegrees[edge[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (inDegrees[i] == 0)
            {
                q.push(i);
            }
        }
        
        while (!q.empty())
        {
            
            int len = q.size();
            while (len--)
            {
                int curNode = q.front();
                q.pop();
                
                for (const auto& nextNode : Graph[curNode])
                {
                    inDegrees[nextNode]--;
                    setRes[nextNode].insert(curNode);
                    for (const auto& node : setRes[curNode])
                    {
                        setRes[nextNode].insert(node);
                    }
                    if (inDegrees[nextNode] == 0)
                    {
                        q.push(nextNode);
                    }
                }
            }
        }
        
        for (auto& item : setRes)
        {
            vector<int> temp(item.begin(), item.end());
            res.push_back(temp);
        }
        return res;
    }
};