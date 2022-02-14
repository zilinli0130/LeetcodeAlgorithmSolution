class Solution {
public:
    int countSubstrings(string t) {
        
        string s = "#";
        for (auto c : t) {
            s.push_back(c);
            s.push_back('#');
        }
        
        int n = s.size();
        vector<int> p(n);
        
        int maxCtr = -1;
        int maxRight = -1;
        for (int i = 0; i < n; i++) {
            
            int r = 0;
            if (i <= maxRight) {
                
                int j = 2 * maxCtr - i;
                r = min(p[j], maxRight - i);
                while (i - r >= 0 && i + r < n && s[i - r] == s[i + r]) {
                    r++;
                }
                
            } else {
                r = 0;
                while (i - r >= 0 && i + r < n && s[i - r] == s[i + r]) {
                    r++;
                }
            }
            p[i] = r - 1;
            if (i + p[i] > maxRight) {
                maxRight = i + p[i];
                maxCtr = i;
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += (p[i] + 1)/2;
        }
        return res;
    }
};         