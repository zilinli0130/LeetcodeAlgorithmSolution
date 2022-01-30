class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        
        queue<int> q;
        int n = favorite.size();
        vector<int> inDegree(n,0);
        vector<int> visited(n,0);
        vector<int> depth(n,1); 
        
        //Topological sort to eliminate nodes with indegree of 0    
        for (int i = 0; i < n; i++) {
            inDegree[favorite[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                visited[i] = 1;
                q.push(i);
            }
        }
        while (!q.empty()) {
            
            int curNode = q.front();
            q.pop();
            int nxtNode = favorite[curNode];
            inDegree[nxtNode]--;
            if (inDegree[nxtNode] == 0) {
                q.push(nxtNode);
                visited[nxtNode] = 1;
            }
            depth[nxtNode] = depth[curNode] + 1;
        }
        
        //Result counting
        int maxPolyCircle = 0;
        int totalBinaryCircleAndLink = 0;
        for (int i = 0; i < n; i++) {
            
            if (visited[i] == 1) continue;
            int count = 0;
            int j = i;
            while (visited[j] == 0) {
                visited[j] = 1;
                j = favorite[j];
                count++;
            }
            
            if (count >= 3) {
                maxPolyCircle = max(maxPolyCircle, count);
            } else if (count == 2) {
                totalBinaryCircleAndLink += depth[j] + depth[favorite[j]];             
            }
        }
        return max(maxPolyCircle, totalBinaryCircleAndLink);
    }
};