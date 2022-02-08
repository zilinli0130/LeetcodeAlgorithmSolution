class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int i = 0;
        int res = 0;
        vector<int> count(26, 0);
        for (int j = 0; j < s.size(); j++) {
            
            count[s[j]-'A']++;
            int maxCount = *max_element(count.begin(), count.end());
            if ((j - i + 1) - maxCount <= k) {
                res = max(res, j - i + 1);
            } else {
                count[s[i]-'A']--;
                i++;
            }
        }
        return res;
    }
};