class Solution {
public:
    int trap(vector<int>& height) {
        
        int res = 0;
        stack<int> Stack;
        int n = height.size();
        
        for (int i = 0; i < n; i++) {
            
            if (Stack.empty()) {
                Stack.push(i);
            } else if (height[Stack.top()] > height[i]) {
                Stack.push(i);
            } else if (height[Stack.top()] <= height[i]) {
                
                while (!Stack.empty() && height[Stack.top()] <= height[i]) {
                    
                    int base = height[Stack.top()];
                    Stack.pop();
                    if (Stack.empty()) continue;
                    int h = min(height[Stack.top()], height[i]) - base;
                    int w = i - Stack.top() - 1;
                    res += h*w;
                }
                Stack.push(i);
            }
        }
        return res;
    }
};