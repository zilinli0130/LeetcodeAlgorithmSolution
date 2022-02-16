class Solution {
    unordered_map<int,int> Ancestors;
    unordered_map<int,int> unionMap;
    
    int FindAncestor(int x) {
        if (Ancestors[x] != x) {
            Ancestors[x] = FindAncestor(Ancestors[x]);
        }
        return Ancestors[x];
    }
    
    void Union(int x, int y) {
        x = Ancestors[x];
        y = Ancestors[y];
        if (x < y) {
            Ancestors[y] = x;
        } else {
            Ancestors[x] = y;
        }
    }
    
public:
    int countServers(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int encode = i * 250 + j;
                    Ancestors[encode] = encode;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            
            int pseudoRootNode = -1;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && pseudoRootNode == -1) {
                    pseudoRootNode = i * 250 + j;
                    continue;
                }
                if (grid[i][j] == 1) {
                    int encode = i * 250 + j;
                    if (FindAncestor(encode) != FindAncestor(pseudoRootNode)) {
                        Union(encode, pseudoRootNode);
                    }
                }
            }
        }
        
        for (int j = 0; j < n; j++) {
            
            int pseudoRootNode = -1;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 1 && pseudoRootNode == -1) {
                    pseudoRootNode = i * 250 + j;
                    continue;
                }
                if (grid[i][j] == 1) {
                    int encode = i * 250 + j;
                    if (FindAncestor(encode) != FindAncestor(pseudoRootNode)) {
                        Union(encode, pseudoRootNode);
                    }
                }
            }
        }
        
        for (auto& node : Ancestors) {
            int rootNode = FindAncestor(node.first);
            unionMap[rootNode]++;
        }
        
        int res = 0;
        for (auto& group : unionMap) {
            res += group.second > 1 ? group.second : 0;
        }
        return res;
    }
};