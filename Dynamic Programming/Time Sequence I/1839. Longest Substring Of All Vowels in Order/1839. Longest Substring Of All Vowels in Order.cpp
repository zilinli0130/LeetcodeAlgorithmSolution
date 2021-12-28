class Solution {
    unordered_map<char, int> Map{{'a',1},{'e',2},{'i',3},{'o',4},{'u',5}};
public:
    int longestBeautifulSubstring(string word) {
        
        int res = 0;
        int n = word.size();
        vector<int> dp_old(6, INT_MIN);
        vector<int> dp_new(6, INT_MIN);
        dp_new[0] = 0;
        dp_old[0] = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= 5; j++) {
                
                if (Map[word[i]] == j) {
                    dp_new[j] = max(dp_old[j - 1], dp_old[j]) + 1;
                } else {
                    dp_new[j] = INT_MIN;
                }
                
            }
            res = max(res, dp_new[5]);
            dp_old = dp_new;
        }
        return res;
    }
};