class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        if (bank.size() == 0) {
            if (start == end) {
                return 0;
            } else {
                return -1;
            }
        }
        
        unordered_set<string> visited;
        unordered_set<char> charSet{'A','C','G','T'};
        unordered_set<string> bankSet(bank.begin(), bank.end());
        queue<string> q;
        q.push(start);
        
        int res = -1;
        while (!q.empty()) {
            
            res++;
            int len = q.size();
            while (len--) {
                
                string cur = q.front();
                cout << cur << endl;
                q.pop();

                if (visited.find(cur) != visited.end()) continue;
                visited.insert(cur);
                
                if (cur == end) return res;
                
                for (int i = 0; i < 8; i++) {
                    
                    char temp = cur[i];
                    for (auto& item : charSet) {
                        if (item == temp) continue;
                        string next = cur;
                        next[i] = item;
                        if (visited.find(next) != visited.end()) continue;
                        if (bankSet.find(next) == bankSet.end()) continue;
                        q.push(next);
                    }
                }
            } 
        }
        return -1;
    }
};