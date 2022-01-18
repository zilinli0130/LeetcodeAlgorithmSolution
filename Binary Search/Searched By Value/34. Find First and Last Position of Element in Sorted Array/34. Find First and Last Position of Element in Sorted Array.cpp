class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = 1 / 2;
        cout << a << endl;
        
        if (nums.size() == 0) {
            return {-1,-1};
        }
        
        vector<int> res;
        
        //Find the lower bound
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (nums[l] == target) {
            res.push_back(l);
        } else {
            res.push_back(-1);
        }
        
        //Find the upper bound
        l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2 + 1;
            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        if (nums[l] == target) {
            res.push_back(l);
        } else {
            res.push_back(-1);
        }
        return res;
    }
};