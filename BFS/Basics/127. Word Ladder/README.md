# 127. Word Ladder

###### Tag: BFS, Bidirectional BFS

###### Time: O(N*26*l) in average, O(26^l) in worst case
###### Space: O(N*26*l) in average, O(26^l) in worst case




```
Naive Approach by BFS:

Time: O(N*26*l) in average, O(26^l) in worst case (traverse all the posible words with length l)
Space: O(N*26*l) in average, O(26^l) in worst case

// C++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> Set(wordList.begin(), wordList.end());
        if (Set.find(endWord) == Set.end()) {
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        unordered_map<string, int> visited;
        
        int step = 0;
        while (!q.empty()) {
            
            step++;
            int len = q.size();
            while (len--) {
                
                string curWord = q.front();
                q.pop();
                
                if (visited[curWord] == 1) continue;
                visited[curWord] = 1;
                
                if (curWord == endWord) {
                    return step;
                }
                
                for (int i = 0; i < curWord.size(); i++) {
                    
                    char temp = curWord[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        curWord[i] = j;
                        if (Set.find(curWord) == Set.end()) continue;
                        if (visited[curWord] == 1) continue;
                        q.push(curWord);
                    }
                    curWord[i] = temp;
                }
            }
        }
        return 0;
    }
};

// Java
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        
        Set<String> visited = new HashSet<>();
        Queue<String> q = new LinkedList<>();
        Set<String> hashSet = new HashSet<>(wordList);
        q.offer(beginWord);
        
        int step = 0;
        while (!q.isEmpty()) {
            
            step++;
            int len = q.size();
            while (len-- > 0) {
                
                String curWord = q.poll();
                
                if (visited.contains(curWord)) continue;
                visited.add(curWord);
                
                if (curWord.equals(endWord)) {
                    return step;
                }
                
                for (int i = 0; i < curWord.length(); i++) {
                    
                    char[] word = curWord.toCharArray();
                    for (char j = 'a'; j <= 'z'; j++) {
                        if (j == curWord.charAt(i)) continue;
                        word[i] = j;
                        String tempWord = String.valueOf(word);
                        if (!hashSet.contains(tempWord)) continue;
                        if (visited.contains(tempWord)) continue;
                        q.offer(tempWord);
                    }
                }
            }
        }
        
        return 0;
    }
}

```