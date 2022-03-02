class Solution {
    vector<int> Ancestor;
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        unordered_set<int> Set;
        int n = isConnected.size();
        for (int i = 0; i < n; i++) {
            Ancestor.push_back(i);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                if (i != j && isConnected[i][j] == 1) {
                    if (FindAncestor(i) != FindAncestor(j)) {
                        Union(i,j);
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            Ancestor[i] = FindAncestor(i);
            Set.insert(Ancestor[i]);
        }
        return Set.size();
    }
    
    int FindAncestor(int x) {
        
        if (Ancestor[x] != x) {
            Ancestor[x] = FindAncestor(Ancestor[x]);
        }
        return Ancestor[x];
    }
    
    void Union (int x, int y) {
        
        x = Ancestor[x];
        y = Ancestor[y];
        if (x <= y) {
            Ancestor[y] = x;
        } else {
            Ancestor[x] = y;
        }
    }
};