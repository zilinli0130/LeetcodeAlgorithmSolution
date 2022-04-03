class Solution {
public:
    string reverseVowels(string s) {
        
        unordered_set<char> Set{'a','e','i','o','u','A','E','I','O','U'};
        
        int l = 0, r = s.size() - 1;
        while (l < r) {
            
            if (Set.find(s[l]) != Set.end() && Set.find(s[r]) != Set.end()) {
                swap(s[l], s[r]);
                l++;
                r--;
            } else if (Set.find(s[l]) != Set.end()) {
                r--;
            } else if (Set.find(s[r]) != Set.end()) {
                l++;
            } else {
                l++;
                r--;
            }
        }
        return s;
    }
};