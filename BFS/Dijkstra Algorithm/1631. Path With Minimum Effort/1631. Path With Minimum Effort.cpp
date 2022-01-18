class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        multiset<vector<int>> Set;
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        Set.insert({0,0,0});
        vector<pair<int, int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        
        while (!Set.empty()) {
            
            int effort = (*Set.begin())[0];
            int r = (*Set.begin())[1];
            int c = (*Set.begin())[2];
            Set.erase(Set.begin());
            
            if (visited[r][c]) continue;
            visited[r][c] = 1;
            
            if (r == m - 1 && c == n - 1) {
                return effort;
            }
            
            for (int k = 0; k < 4; k++) {
                
                int x = r + dirs[k].first;
                int y = c + dirs[k].second;
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                if (visited[x][y]) continue;
                if (r == 0 && c == 0) {
                    Set.insert({abs(heights[x][y] - heights[r][c]),x,y});
                } else {
                    Set.insert({max(effort, abs(heights[x][y] - heights[r][c])),x,y});
                }
            }
        }
        return -1;
    }
};