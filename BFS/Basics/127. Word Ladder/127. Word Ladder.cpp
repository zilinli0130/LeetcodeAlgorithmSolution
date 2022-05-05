class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, int> visited;
        unordered_set<string> Set(wordList.begin(), wordList.end());
        if (Set.find(endWord) == Set.end()) {
            return 0;
        }
        
        unordered_set<string> q1;
        unordered_set<string> q2;
        q1.insert(beginWord);
        q2.insert(endWord);
        
        int step = 0;
        while (!q1.empty() && !q2.empty()) {
            
            step++;
            if (q1.size() > q2.size()) {
                std::swap(q1, q2);
            }
            
            unordered_set<string> q;
            for (auto curWord : q1) {
                
                if (visited[curWord]) continue;
                visited[curWord] = 1;
                
                if (q2.find(curWord) != q2.end()) {
                    return step;
                }
                
                for (int i = 0; i < curWord.size(); i++) {
                    
                    char temp = curWord[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        curWord[i] = j;
                        if (Set.find(curWord) == Set.end()) continue;
                        if (visited[curWord]) continue;
                        q.insert(curWord);
                    }
                    curWord[i] = temp;
                }
            }
            std::swap(q, q1);
        }
        return 0;
    }
};