class Solution {
    vector<int> Ancestor;
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        
        vector<bool> res;
        for (int i = 0; i < n; i++) {
            Ancestor.push_back(i);
        }
        
        for (const auto& request : requests) {
            
            int u = request[0], v = request[1];
            int uAncestor = Find(u), vAncestor = Find(v);
            
            if (uAncestor == vAncestor) {
                res.push_back(true);
                continue;
            }
            
            int valid = 1;
            for (const auto& restriction : restrictions) {
                
                int x = restriction[0], y = restriction[1];
                int xAncestor = Find(x), yAncestor = Find(y);
                
                if ((xAncestor == uAncestor && yAncestor == vAncestor) || (xAncestor == vAncestor && yAncestor == uAncestor)) {
                    valid = 0;
                    break;
                }
            }
            res.push_back(valid);
            if (valid) {
                Union(u, v);
            }
        }
        return res;
    }
    
    int Find(int x) {
        
        if (Ancestor[x] != x) {
            Ancestor[x] = Find(Ancestor[x]);
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