class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> Stack;
        int n = nums.size();
        vector<int> res(2*n, -1);
        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        
        for (int i = 0; i < 2*n; i++) {
            
            if (Stack.empty()) {
                Stack.push(i);
            } else if (nums[Stack.top()] > nums[i]) {
                Stack.push(i);
            } else if (nums[Stack.top()] <= nums[i]) {
                
                while (!Stack.empty() && nums[Stack.top()] < nums[i]) {
                    res[Stack.top()] = nums[i];
                    Stack.pop();
                }
                Stack.push(i);
            }
        }
        return vector<int>(res.begin(), res.begin() + n);
    }
};