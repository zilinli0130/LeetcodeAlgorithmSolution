class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<int> colors(n, 0);
        vector<vector<int>> graph(n);
        for (const auto& path : paths) {
            graph[path[0] - 1].push_back(path[1] - 1);
            graph[path[1] - 1].push_back(path[0] - 1);
        }
        
        
        for (int i = 0; i < n; i++) {
            if (colors[i] != 0) {
                continue;
            }
            
            unordered_set<int> invalidColors;
            for (const auto& neighbor : graph[i]) {
                if (colors[neighbor] == 0) {
                    continue;
                }
                invalidColors.insert(colors[neighbor]);
                
            }
            
            for (int color = 1; color <= 4; color++) {
                if (invalidColors.find(color) == invalidColors.end()) {
                    colors[i] = color;
                    break;
                }
            }
        }
        return colors;
    }
};