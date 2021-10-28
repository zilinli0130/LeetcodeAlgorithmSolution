class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int res = 0;
        queue<int> q;   
        int n = numCourses;
        vector<int> InDegree(n, 0);
        vector<vector<int>> Graph(n);
        
        for (auto item : prerequisites) {
            Graph[item[0]].push_back(item[1]); // 0 -> 1
            InDegree[item[1]]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (InDegree[i] == 0) {
                q.push(i);
                res++;
            } 
        }
        
        while (!q.empty()) {
            
            int currentNode = q.front();
            q.pop();
            
            for (auto nextNode : Graph[currentNode]) {
                
                InDegree[nextNode]--;
                if (InDegree[nextNode] == 0) {
                    q.push(nextNode);
                    res++;
                }
            }
        }
        return res == n;            
    }
};

// [cur,prev]
// 0 -> #
// 1 -> 4
// 2 -> 4
// 3 -> 1,2
// 4 -> #

