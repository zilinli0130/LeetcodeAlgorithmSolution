class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        string res = "";
        stack<char> Stack;
        unordered_map<char, int> Map;
        unordered_map<char, bool> visited;
        
        for (const auto& ch : s) {
            Map[ch]++;
        }
        
        for (const auto& ch : s) {
            
            if (visited[ch] == true) {
                
                Map[ch]--;
                
            } else if (Stack.empty() || Stack.top() < ch) {
                
                if (visited[ch] == false) {
                    Stack.push(ch);
                    Map[ch]--;
                    visited[ch] = true;
                } 
                
            } else {
                
                while (!Stack.empty() && Stack.top() >= ch && Map[Stack.top()] > 0) {
                    visited[Stack.top()] = false;
                    Stack.pop();
                }
                if (visited[ch] == false) {
                    Stack.push(ch);
                    visited[ch] = true;
                }
                Map[ch]--;
            }
        }
        
        while (!Stack.empty()) {
            res += Stack.top();
            Stack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};