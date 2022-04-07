class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        if (s.size() == 0) {
            return 0;
        }
      
        int res = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int idx1 = 0, idx2 = 0;
        while (idx1 < g.size()) {
            
            if (s[idx2] < g[idx1]) {
                idx2++;
            } else {
                idx1++;
                idx2++;
                res++;
            }
            
            if (idx2 == s.size()) {
                break;
            }
        }
        return res;
    }
};