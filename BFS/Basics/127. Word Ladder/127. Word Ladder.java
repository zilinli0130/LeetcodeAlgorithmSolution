class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        
        Set<String> q1 = new HashSet<>();
        Set<String> q2 = new HashSet<>();
        Set<String> visited = new HashSet<>();
        Set<String> hashSet = new HashSet<>(wordList);
        
        if (!wordList.contains(endWord)) {
            return 0;
        }
        
        q1.add(beginWord);
        q2.add(endWord);
        
        int step = 0;
        while (!q1.isEmpty() && !q2.isEmpty()) {
            
            step++;
            if (q1.size() > q2.size()) {
                Set<String> temp = q1;
                q1 = q2;
                q2 = temp;
            }
            
            Set<String> q = new HashSet<>();
            for (String curWord : q1) {
                
                if (visited.contains(curWord)) continue;
                visited.add(curWord);
                
                if (q2.contains(curWord)) {
                    return step;
                }
                
                for (int i = 0; i < curWord.length(); i++) {
                    
                    char[] word = curWord.toCharArray();
                    for (char j = 'a'; j <= 'z'; j++) {
                        if (curWord.charAt(i) == j) continue;
                        word[i] = j;
                        String tempWord = String.valueOf(word);
                        if (!hashSet.contains(tempWord)) continue;
                        if (visited.contains(tempWord)) continue;
                        q.add(tempWord);
                    }
                }
            }  
            q1 = q;
        }
        return 0;
    }
}