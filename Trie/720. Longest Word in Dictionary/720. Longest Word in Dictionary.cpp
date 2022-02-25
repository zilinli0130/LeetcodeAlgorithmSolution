class Solution {
    struct TrieNode {
      TrieNode* next[26];  
    };
    TrieNode* root = new TrieNode();
    
    void insertWord(string s) {
        TrieNode* node = root;
        for (auto& c : s) {
            if (node->next[c-'a'] == nullptr) {
                node->next[c-'a'] = new TrieNode();
            }
            node = node->next[c-'a'];
        }
    }
    
    bool checkOK(string s) {
        
        int n = s.size();
        TrieNode* node = root;
        for (int i = 0; i < n; i++) {
            if (node->next[s[i]-'a'] == nullptr) {
                if (i != n - 1) {
                    return false;
                } else {
                    return true;
                }
            }
            node = node->next[s[i]-'a'];
        }
        return true;
    }
    
public:
    string longestWord(vector<string>& words) {
        
        string res = "";
        sort(words.begin(), words.end());
        
        for (auto& word : words) {
            if (word.size() == 1) {
                insertWord(word);
                if (res == "") {
                    res = word;
                } else if (res.size() == 1) {
                    res = word < res ? word : res;
                }
            } else {
                
                if (checkOK(word)) {
                    if (word.size() > res.size()) {
                        res = word;
                    } else if (word.size() == res.size()) {
                        res = word < res ? word : res;
                    }
                    insertWord(word);
                }
            }
        }
        return res;
    }
};