class Solution {
    struct TrieNode {
        bool end = false;
        TrieNode* next[26] = {nullptr};
    };
    string s;
    vector<string> res;
    TrieNode* root = new TrieNode();
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        this->s = s;
        for (auto& word : wordDict) {
            TrieNode* node = root;
            for (auto& c : word) {
                if (node->next[c-'a'] == nullptr) {
                    node->next[c-'a'] = new TrieNode();
                }
                node = node->next[c-'a'];
            }
            node->end = true;
        }
        string temp = "";
        dfs(0, s.size() - 1, temp);
        delete root;
        return res;
    }
    
    void dfs(int l, int r, string& temp) {
        
        if (l == r) {
            if (searchTrie(l, r)) {
                string temp1 = temp + s[l];
                res.push_back(temp1);
            }
            return;
        } 
        
        if (l > r) {
            string temp2 = temp.substr(0, temp.size() - 1);
            res.push_back(temp2);
            return;
        }
        for (int mid = l; mid <= r; mid++) {
            string str = s.substr(l, mid - l + 1);
            if (searchTrie(l, mid)) {
                temp += str;
                temp += " ";
                dfs(mid + 1, r, temp);
                temp = temp.substr(0, temp.size() - str.size() - 1);
            }
        }
    }
    
    bool searchTrie(int st, int en) {
        
        int idx = st;
        TrieNode* node = root;
        while (idx <= en) {
            
            if (node->next[s[idx]-'a'] == nullptr) {
                return false;
            }
            node = node->next[s[idx]-'a'];
            idx++;
        }
        if (!node->end) {
            return false;
        }
        return true;
    }
};