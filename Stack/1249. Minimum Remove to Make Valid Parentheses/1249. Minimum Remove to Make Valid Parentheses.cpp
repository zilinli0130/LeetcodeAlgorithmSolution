class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n = s.size();
        vector<int> visited(n, 0);
        stack<pair<char,int>> Stack;
        
        for (int i = 0; i < n; i++) {
            
            if (s[i] == '(') {
                Stack.push({s[i],i});
                
            } else if (s[i] == ')') {
                
                if (Stack.empty() || Stack.top().first == ')') {
                    Stack.push({s[i],i});
                } else {
                    Stack.pop();
                }
            }
        }
        
        while (!Stack.empty()) {
            visited[Stack.top().second] = 1;
            Stack.pop();
        }
        
        string res = "";
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            res += s[i];
        }
        return res;
    }
};


