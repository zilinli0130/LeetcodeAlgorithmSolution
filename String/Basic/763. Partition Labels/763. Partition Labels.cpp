class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> res;
        vector<int> lastSeen(26,0);
        for (int i = 0; i < s.size(); i++) {
            lastSeen[s[i]-97] = i;
        }
        
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); i++) {
            r = max(r, lastSeen[s[i]-97]);
            if (i == r) {
                res.push_back(r - l + 1);
                l = r + 1;
            }
        }
        return res;
    }
};