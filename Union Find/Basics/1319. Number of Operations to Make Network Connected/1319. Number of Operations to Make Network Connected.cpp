class Solution {
    vector<int> Ancestors;
    
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if (connections.size() < n - 1) {
            return -1;
        }
        
        Ancestors.resize(n);
        for (int i = 0; i < n; i++) {
            Ancestors[i] = i;
        }
        
        for (auto& connection : connections) {
            
            int a = connection[0];
            int b = connection[1];
            if (FindAncestor(a) != FindAncestor(b)) {
                Union(a, b);
            }
        }
        
        int res = -1;
        for (int i = 0; i < Ancestors.size(); i++) {
            
            int rootNode = FindAncestor(i);
            if (rootNode == i) {
                res++;
            }
        }
        return res;
    }
};