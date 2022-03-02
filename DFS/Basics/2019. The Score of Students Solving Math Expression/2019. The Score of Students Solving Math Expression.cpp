class Solution {
    vector<int>nums;
    vector<char>ops;    
    unordered_set<int> Memo[20][20];
public:
    int scoreOfStudents(string s, vector<int>& answers) {
        
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            while (j < s.size() && isdigit(s[j])) {
                j++;
            }
            nums.push_back(stoi(s.substr(i,j-i)));
            ops.push_back(s[j]);
            i = j;
        }

        dfs(0, nums.size() - 1);

        int correct = correctAns(s);
        int res = 0;
        for (auto ans: answers) {
            if (ans == correct) {
                res += 5;
            } else if (Memo[0][nums.size() - 1].find(ans)!= Memo[0][nums.size() - 1].end()) {
                res += 2;
            }
        }
        return res;
    }

    void dfs(int a, int b) {
        
        if (!Memo[a][b].empty()) return;
        if (a == b) {
            Memo[a][b] = {nums[a]};
            return;
        }
        
        for (int i=a; i<b; i++) {
            
            dfs(a, i);
            dfs(i + 1, b);
            
            for (auto x: Memo[a][i])
                for (auto y: Memo[i+1][b]) {
                    if (ops[i] == '+' && x + y <= 1000)
                        Memo[a][b].insert(x + y);
                    else if (ops[i]=='*' && x * y <= 1000)
                        Memo[a][b].insert(x*y);
                }
        }
    }
    
    int correctAns(string s) {
        
        int idx = 0;
        stack<int> Stack;        
        while (idx < s.size()) {
            
            if (s[idx] == '+') {
                idx++;
                continue;
            }
            
            if (isdigit(s[idx])) {
                Stack.push(s[idx] - '0');
                idx++;
                continue;
            }
            
            if (s[idx] == '*') {
                idx++;
                int num = Stack.top();
                Stack.pop();
                Stack.push(num * (s[idx] - '0'));
                idx++;
            }
        }
        
        int correct = 0;
        while (!Stack.empty()) {
            correct += Stack.top();
            Stack.pop();
        }
        return correct;
    }
};