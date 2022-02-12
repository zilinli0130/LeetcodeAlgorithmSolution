class Solution {
    unordered_map<int, int> Ancestors;
    unordered_map<int, vector<int>> unionMap;
    
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
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        int m = land.size(), n = land[0].size();
        vector<pair<int,int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    int encode = i * 300 + j;
                    Ancestors[encode] = encode;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    int encode1 = i * 300 + j;
                    
                    for (int k = 0; k < 4; k++) {
                        int x = i + dirs[k].first;
                        int y = j + dirs[k].second;
                        if (x < 0 || x >= m || y < 0 || y >= n) continue;
                        if (land[x][y] == 0) continue;
                        
                        int encode2 = x * 300 + y;
                        if (FindAncestor(encode1) != FindAncestor(encode2)) {
                            Union(encode1, encode2);
                        }
                    }
                }
            }
        }
        
        for (auto& item : Ancestors) {
            
            int rootNode = FindAncestor(item.first);
            unionMap[rootNode].push_back(item.first);
        }
        
        vector<vector<int>> res;
        for (auto& farmLand : unionMap) {
            sort(farmLand.second.begin(), farmLand.second.end());
            int i0 = farmLand.second[0] / 300;
            int j0 = farmLand.second[0] % 300;
            int i1 = farmLand.second[farmLand.second.size() - 1] / 300;
            int j1 = farmLand.second[farmLand.second.size() - 1] % 300;
            res.push_back({i0,j0,i1,j1});
        }
        return res;
    }
};