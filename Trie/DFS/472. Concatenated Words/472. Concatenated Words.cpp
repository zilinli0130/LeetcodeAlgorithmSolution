class Solution {
    struct TrieNode {
        bool end = false;
        TrieNode* next[26] = {nullptr};
    };
    TrieNode* root;
    vector<string> res;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        root = new TrieNode();
        sort(begin(words), end(words), 
             [](string& a, string& b) {
                return a.size() < b.size();
             }
        );
        
        for (auto& word : words) {
            
            if (word.size() == 0) continue;
            vector<int> visited(word.size(), 0);
            if (dfs(word, 0, visited)) {
                res.push_back(word);
            }
            
            TrieNode* node  =root;
            for (auto& c : word) {
                if (node->next[c-'a'] == nullptr) {
                    node->next[c-'a'] = new TrieNode();
                }
                node = node->next[c-'a'];
            }
            node->end = true;
        }
        delete root;
        return res;
    }
    
    bool dfs(string word, int idx, vector<int>& visited) {
        
        if (idx == word.size()) {
            return true;
        }
        
        if (visited[idx]) {
            return false;
        }
        
        TrieNode* node = root;
        for (int i = idx; i < word.size(); i++) {
            if (node->next[word[i]-'a'] != nullptr) {
                node = node->next[word[i]-'a'];
                if (node->end && dfs(word, i + 1, visited)) {
                    return true;
                }
            } else {
                break;
            }
        }
        visited[idx] = false;
        return false;
    }
};