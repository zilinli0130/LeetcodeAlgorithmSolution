class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        
        if (heights.size() == 1) return heights[0];
        
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stack<int> Stack;
        int res = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            
            if (Stack.empty() || heights[i] >= heights[Stack.top()]) {
                Stack.push(i);
                continue;
            }
            
            if (heights[i] < heights[Stack.top()]) {
                
                while(!Stack.empty() && heights[i] < heights[Stack.top()]) {
                    
                    int h = heights[Stack.top()];
                    Stack.pop();
                    int w = i - Stack.top() - 1;
                    res = max(res, h*w);
                }
                Stack.push(i);
            }
        }
        return res;
    }
};