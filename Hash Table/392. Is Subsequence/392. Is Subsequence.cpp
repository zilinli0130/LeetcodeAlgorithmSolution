class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        unordered_map<char, vector<int>> Map;
        for (int i = 0; i < t.size(); i++) {
            Map[t[i]].push_back(i);
        }
        
        int nextIdx =-1;
        for (int i = 0; i < s.size(); i++) {
            
            int flag = 0;
            for (const auto& pos : Map[s[i]]) {
                
                if (pos > nextIdx) {
                    nextIdx = pos;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                return false;
            }
        }
        return true;
    }
};