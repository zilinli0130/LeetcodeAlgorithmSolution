class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        int n = T.size();
        vector<int> res(n, 0);
        stack<int> Stack;
        
        for (int i = 0; i < n; i++) {
            
            if (Stack.empty()) {
                Stack.push(i);
            } else if (T[Stack.top()] > T[i]) {
                Stack.push(i);
            } else if (T[Stack.top()] <= T[i]) {
                
                while (!Stack.empty() && T[Stack.top()] < T[i]) {
                    res[Stack.top()] = i - Stack.top();
                    Stack.pop();
                }
                Stack.push(i);
            }
        }
        return res;
    }
};

// 75,71,69,72,76




