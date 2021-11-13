class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;
        stack<int> Stack;
        int m = nums1.size();
        int n = nums2.size();
        unordered_map<int, int> Map;
        for (auto num : nums2) {Map[num] = -1;}
        
        for (int i = 0; i < n; i++) {
            
            if (Stack.empty()) {
                Stack.push(nums2[i]);
            } else if (Stack.top() > nums2[i]) {
                Stack.push(nums2[i]);
            } else if (Stack.top() <= nums2[i]) {
                
                while (!Stack.empty() && Stack.top() <= nums2[i]) {
                    Map[Stack.top()] = nums2[i];
                    Stack.pop();
                }
                Stack.push(nums2[i]);
            }
        }
        
        for (auto num : nums1) {
            // cout << num << " " << Map[num] << endl;
            res.push_back(Map[num]);
        }
        return res;
    }
};

// 4,3,2,1,5