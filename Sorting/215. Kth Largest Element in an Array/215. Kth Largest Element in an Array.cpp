class Solution {
    static bool cmp(string& a, string& b) {
        if (a.size() == b.size()) {
            return a < b;
        }
        return a.size() > b.size();
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        
        string res = "";
        sort(dictionary.begin(), dictionary.end(), cmp);
        for (const auto& word : dictionary) {
            
            int idx1 = 0, idx2 = 0;
            while (idx2 < s.size()) {
                if (s[idx2] == word[idx1]) {
                    idx1++;
                }
                idx2++;
            }
            if (idx1 == word.size()) {
                return word;
            }
        }
        return res;
    }
};