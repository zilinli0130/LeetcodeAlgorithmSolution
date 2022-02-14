class WordDictionary {
    struct TrieNode {
        bool end = false;
        TrieNode* next[26] = {nullptr};
    };
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (auto& c : word) {
            if (node->next[c-'a'] == nullptr) {
                node->next[c-'a'] = new TrieNode();
            }
            node = node->next[c-'a'];
        }
        node->end = true;
    }
    
    bool dfs(TrieNode* node, const char* word, int idx, int limit) {
        
        if (node == nullptr) {
            return false;
        }
        
        if (idx == limit) {
            return node->end;
        }
        
        if (word[idx] != '.') {
            return dfs(node->next[word[idx]-'a'], word, idx + 1);
        } else {
            
            for (int k = 0; k < 26; k++) {
                if (dfs(node->next[k], word, idx + 1, limit)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool search(string word) {
        return dfs(root, word.c_str(), 0, word.size());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */